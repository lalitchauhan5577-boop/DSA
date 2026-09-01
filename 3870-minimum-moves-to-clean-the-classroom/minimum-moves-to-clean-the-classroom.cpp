class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int L = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign IDs to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = L++;
                }
            }
        }

        if (L == 0)
            return 0;

        int fullMask = (1 << L) - 1;

        /*
            best[r][c][mask] =
            maximum energy with which we have reached
            (r,c) having collected 'mask' litter.
        */
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << L, -1))
        );

        // r, c, mask, remaining energy
        queue<array<int, 4>> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {
                auto [r, c, mask, en] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                // If energy is 0, we must be standing on R
                if (en == 0 && classroom[r][c] != 'R')
                    continue;

                // R restores energy
                if (classroom[r][c] == 'R')
                    en = energy;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Cannot move without energy
                    if (en == 0)
                        continue;

                    int newEnergy = en - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int k = id[nr][nc];
                        newMask |= (1 << k);
                    }

                    // Reset energy on R
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    /*
                        If we have already reached the same
                        position + mask with >= energy,
                        this state is useless.
                    */
                    if (newEnergy <= best[nr][nc][newMask])
                        continue;

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};