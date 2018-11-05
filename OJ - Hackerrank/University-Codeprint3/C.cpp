
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[100][100];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    char d; cin >> d;
    int x, y; cin >> x >> y;
    ++x; ++y;
    int idx = 0;
    const char* lb = "nesw";
    int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    auto ok = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= n && !a[x][y];
    };

    d = strchr(lb, d) - lb;
    while(true) {
        // cout << x << ' ' << y << endl;
        a[x][y] = ++idx;
        if(idx == n * n) break; 
        int nx = x + dir[d % 4][0], ny = y + dir[d % 4][1];
        if(!ok(nx, ny)) {
            nx = x + dir[(d + 1) % 4][0], ny = y + dir[(d + 1) % 4][1];
            if(!ok(nx, ny)) {
                nx = x + dir[(d + 3) % 4][0], ny = y + dir[(d + 3) % 4][1];
                if(!ok(nx, ny)) {
                    nx = x + dir[(d + 2) % 4][0], ny = y + dir[(d + 2) % 4][1];
                    assert(ok(nx, ny));
                }
            }
        }
        x = nx; y = ny;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << a[i][j] << " \n"[j == n];
        }
    }
    return 0;
}
