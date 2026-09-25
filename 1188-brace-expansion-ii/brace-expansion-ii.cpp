class Solution {
public:
    string s;
    int pos = 0;

    set<string> parseExpression() {
        set<string> result;
        set<string> current;

        bool hasCurrent = false;

        while (pos < s.size() && s[pos] != '}') {

            if (s[pos] == ',') {
                // Union
                result.insert(current.begin(), current.end());
                current.clear();
                hasCurrent = false;
                pos++;
            }
            else {
                set<string> part;

                if (s[pos] == '{') {
                    pos++; // skip '{'
                    part = parseExpression();
                    pos++; // skip '}'
                }
                else {
                    // Single lowercase letter
                    part.insert(string(1, s[pos]));
                    pos++;
                }

                if (!hasCurrent) {
                    current = part;
                    hasCurrent = true;
                }
                else {
                    // Concatenation
                    set<string> temp;

                    for (string a : current) {
                        for (string b : part) {
                            temp.insert(a + b);
                        }
                    }

                    current = temp;
                }
            }
        }

        // Add last part
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};