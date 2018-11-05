
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int r, b;
int f[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> r >> b;
        int x = sqrt(r) + 10;
        int y = sqrt(b) + 10;
        vector<pair<int, int>> v;
        for(int i = 0; i <= x; ++i) {
            for(int j = 0; j <= y; ++j) {
                if(i + j > 0) {
                    v.push_back({i, j});
                }
            }
        }
        // cout << r << ' ' << b << endl;
        memset(f, 0, sizeof f);
        for(const auto& p : v) {
            int x = p.first, y = p.second;
            // cout << x << ' ' << y << endl;
            for(int i = r; i >= 0; --i) {
                for(int j = b; j >= 0; --j) {
                    if(i >= x && j >= y) {
                        f[i][j] = max(f[i][j], f[i - x][j - y] + 1);     
                    }
                }
            }
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << f[r][b] << '\n';
    }
    return 0;
}
