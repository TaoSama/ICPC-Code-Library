
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N][N];
int c[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    while(cin >> n >> m) {
        memset(c, 0, sizeof c);
        for(int i = 1; i <= n; ++i) {
            cin >> (s[i] + 1);
            for(int j = 1; j <= m; ++j) c[i][j] = s[i][j] == '#';
        }
        auto check = [&](int x, int y) {
            int cnt = 0;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    if(i == 0 && j == 0) continue;
                    int nx = x + i, ny = y + j;
                    if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    cnt += s[nx][ny] == '#';
                }
            }
            return cnt == 8;
        };
        auto go = [&](int x, int y) {
            int cnt = 0;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    if(i == 0 && j == 0) continue;
                    int nx = x + i, ny = y + j;
                    --c[nx][ny];
                }
            }
        };
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(check(i, j)) {
                    go(i, j);
                }
            }
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                ok &= c[i][j] <= 0;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
