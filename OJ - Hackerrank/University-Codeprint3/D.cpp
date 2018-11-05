
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N][N];
int f[N][N];

int d[3][2] = {-1, 0, 0, -1, -1, -1};
int sg(int x, int y) {
    int& ret = f[x][y];
    if(ret != -1) return ret;
    int nxt[10] = {};
    for(int i = 0; i < 3; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
            if(s[nx][ny] == 'X') continue;
            nxt[sg(nx, ny)] = 1;
        }
    }
    for(int i = 0; i < 10; ++i) if(!nxt[i]) return ret = i;
    return -1;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int q; cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);
        vector<pair<int, int>> kings;
        int xorsum = 0;
        memset(f, -1, sizeof f);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s[i][j] == 'K') {
                    kings.emplace_back(i, j);
                    xorsum ^= sg(i, j);
                }
            }
        }
        // for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cout << i << ' ' << j << ' ' << sg(i, j) << endl;
        if(!xorsum) {
            cout << "LOSE\n";
            continue;
        }
        int cnt = 0;
        for(const auto& p : kings) {
            int x, y; tie(x, y) = p;
            for(int i = 0; i < 3; ++i) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    if(s[nx][ny] == 'X') continue;
                    cnt += (xorsum ^ sg(x, y) ^ sg(nx, ny)) == 0;
                }
            }
        }
        cout << "WIN " << cnt << endl;
    }
    return 0;
}
