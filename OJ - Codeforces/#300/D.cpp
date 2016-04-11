//
//  Created by TaoSama on 2015-04-27
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

char a[55][55], b[105][105];
int n, x[2505], y[2505], cnt;
bool vis[55][55];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        cnt = 0;
        memset(b, '.', sizeof b);
        memset(vis, false, sizeof vis);

        for(int i = 1; i <= n; ++i) {
            cin >> a[i] + 1;
            for(int j = 1; j <= n; ++j) {
                if(a[i][j] == 'o') {
                    x[++cnt] = i;
                    y[cnt] = j;
                }
            }
        }

        for(int i = - n + 1; i < n; ++i) {
            for(int j = -n + 1; j < n; ++j) {
                if(i == 0 && j == 0) continue;
                bool ok = true;
                for(int k = 1; k <= cnt; ++k) {
                    int nx = x[k] + i, ny = y[k] + j;
                    if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    if(a[nx][ny] == '.') {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    b[n + i][n + j] = 'x';
                    for(int k = 1; k <= cnt; ++k) {
                        int nx = x[k] + i, ny = y[k] + j;
                        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                //cout<<a[i][j];
                if(a[i][j] == 'x' && !vis[i][j]) {
                    ok = false;
                    break;
                }
            }
            //cout<<endl;
            if(!ok) break;
        }

		//ok = true;
        if(ok) {
            cout << "YES\n";
            b[n][n] = 'o';
            for(int i = 1; i <= 2 * n - 1; ++i) {
                for(int j = 1; j <= 2 * n - 1; ++j)
                    cout << b[i][j];
                cout << '\n';
            }
        } else cout << "NO\n";
    }
    return 0;
}
