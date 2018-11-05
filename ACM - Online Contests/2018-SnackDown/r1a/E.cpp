
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 600 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int O = 300;

char s[N][N];
int g[N][N];
int cnt1[N][N], cnt2[N][N];
int ans[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; ++i) {
            cin >> (s[i] + 1);
            for (int j = 1; j <= m; ++j) {
                g[i - j + O][i + j] = s[i][j] - '0';
            }
        }
        // for (int i = 1; i < N; ++i) {
            // for(int j = 1; j < N; ++j) {
                // cout << g[i][j];
            // }
            // cout << endl;
        // }
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                cnt1[i][j] = cnt1[i][j - 1] + g[i][j];
                cnt2[j][i] = cnt2[j - 1][i] + g[j][i];
            }
        }

        memset(ans, 0, sizeof ans);
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                if (g[i][j] != 1) continue;
                for (int k = 1; k < N; ++k) {
                    int x1 = max(0, i - k), x2 = min(i + k, N - 1);    
                    int y1 = max(0, j - k), y2 = min(j + k, N - 1);    
                    int tmp = 0;
                    tmp += cnt1[x1][y2] - cnt1[x1][max(0, y1 - 1)];
                    // if (i == 6 && j == 5 && k == 3) cout <<tmp << endl;
                    tmp += cnt1[x2][y2] - cnt1[x2][max(0, y1 - 1)];
                    // if (i == 6 && j == 5 && k == 3) cout <<tmp << endl;
                    tmp += cnt2[max(0, x2 - 1)][y1] - cnt2[x1][y1];
                    // if (i == 6 && j == 5 && k == 3) {
                        // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
                        // cout << cnt2[max(0, x2 - 1)][y1] << ' ' << cnt2[x1][y1] << endl;
                        // cout <<tmp << endl;
                    // }
                    tmp += cnt2[max(0, x2 - 1)][y2] - cnt2[x1][y2];
                    // if ( tmp > 0 )
                    // cout << i << ' ' << j << ' ' << k << ' ' << tmp << endl;
                    ans[k] += tmp;
                }
            }
        }
        for (int i = 1; i <= n + m - 2; ++i) {
            cout << ans[i] / 2 << " \n"[i == n + m - 2];
        }
    }
    return 0;
}
