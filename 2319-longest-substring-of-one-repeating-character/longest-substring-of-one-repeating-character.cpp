class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen, best, len;

        Node() {
            leftChar = rightChar = '#';
            leftLen = rightLen = best = len = 0;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;
        if (a.leftLen == a.len && a.rightChar == b.leftChar)
            res.leftLen += b.leftLen;

        res.rightLen = b.rightLen;
        if (b.rightLen == b.len && a.rightChar == b.leftChar)
            res.rightLen += a.rightLen;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.rightLen + b.leftLen);

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx].leftChar = seg[idx].rightChar = s[l];
            seg[idx].leftLen = seg[idx].rightLen = seg[idx].best = 1;
            seg[idx].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx].leftChar = seg[idx].rightChar = c;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, c);
        else
            update(2 * idx + 1, mid + 1, r, pos, c);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;
        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};