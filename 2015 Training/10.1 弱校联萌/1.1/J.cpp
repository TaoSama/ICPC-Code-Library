//
//  Created by TaoSama on 2015-10-01
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int x[N], y[N];
int n, mp[N][N];

int d[][2] = {1, 0, 0, -1, -1, 0, 0, 1};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> xs, ys;
        xs.push_back(0);
        ys.push_back(0);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            xs.push_back(x[i]);
            ys.push_back(y[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        sort(ys.begin(), ys.end());
        ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

        memset(mp, -1, sizeof mp);
        for(int i = 1; i <= n; ++i) {
            int u = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
            int v = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
            mp[u][v] = 0;
//            printf("%d %d\n", u, v);
        }

        //-> | <- ^
        int sx = lower_bound(xs.begin(), xs.end(), 0) - xs.begin();
        int sy = lower_bound(ys.begin(), ys.end(), 0) - ys.begin();
//        printf("sx: %d sy: %d\n", sx, sy);
        int dir = 0, ans = 0;
        bool done = false;
        while(true) {
            for(int k = 1; ; ++k) {
                int tx = sx + k * d[dir][0], ty = sy + k * d[dir][1];
                if(tx < 0 || tx > n || ty < 0 || ty > n) {
                    done = true;
                    break;
                }
                int &ob = mp[tx][ty];
                if(ob >= 0) {
//                    printf("x: %d %d\n", tx, ty);
                    if(ob >> dir & 1) {
                        ans = -1;
                        break;
                    }
                    ++ans;
                    sx = sx + (k - 1) * d[dir][0], sy = sy + (k - 1) * d[dir][1];
                    ob |= 1 << dir;
                    dir = (dir + 1) % 4;
                    break;
                }
            }
            if(done || ans == -1) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
