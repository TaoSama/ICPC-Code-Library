
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[4][N][4];
int g[4][N][4];
char s[4][N];

vector<tuple<int, int, int>> go[4] = {
    { {0, 1, 2}, {0, 1, 3} },
    { {0, 1, 2}, {0, 1, 3} },
    { {1, 0, 0} },
    { {-1, 0, 1} }
};

int main(){
#ifdef LOCAL
//    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= 3; ++i) cin >> (s[i] + 1);
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        queue<tuple<int, int, int>> q;
        f[1][0][0] = 1;
        g[1][0][0] = 1;
        q.push({1, 0, 0});
        while(q.size()) {
            int i, j, k; tie(i, j, k) = q.front();
            q.pop();
            for(const auto& p : go[k]) {
                int di, dj, nk; tie(di, dj, nk) = p;
                int ni = i + di, nj = j + dj;
                if(ni < 1 || ni > 3 || nj < 1 || nj > n || s[ni][nj] == '#') continue;
                f[ni][nj][nk] += f[i][j][k];
                if(f[ni][nj][nk] >= MOD) f[ni][nj][nk] -= MOD;
                if(!g[ni][nj][nk]) {
                    g[ni][nj][nk] = 1;
                    q.push({ni, nj, nk});
                }
            }
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << f[3][n][0] << '\n';
    }
    return 0;
}
