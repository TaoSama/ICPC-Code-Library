//
//  Created by TaoSama on 2016-10-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, K;
const int OFF = 1e5;
vector<int> mainD[N << 1], viceD[N << 1];
typedef long long LL;

struct Point {
    int x, y;
} ps[N];

LL ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &K) == 3) {
        for(int i = 0; i < N << 1; ++i) {
            mainD[i].clear();
            viceD[i].clear();
        }

        for(int i = 1; i <= K; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            ps[i] = {x, y};
            mainD[y - x + OFF].push_back(i);
            viceD[y + x].push_back(i);
            ans[i] = -1;
        }

        LL T = 0;
        set<pair<int, int> > s;
        int x = 0, y = 0, d = 0, step = 0;
        static int dir[][2] = {{1, 1}, { -1, 1}, { -1, -1}, {1, -1}};
        while(true) {
            if(d == 0) {
                for(int p : mainD[y - x + OFF]) {
                    if(~ans[p]) continue;
                    ans[p] = T + abs(ps[p].x - x);
                }
                step = min(n - x, m - y);
                x += step; y += step;

                if(x == n && y == m) break;
                if(x == n) d = 1;
                else d = 3;
            } else if(d == 1) {
                for(int p : viceD[y + x]) {
                    if(~ans[p]) continue;
                    ans[p] = T + abs(ps[p].x - x);
                }
                step = min(x, m - y);
                x -= step; y += step;

                if(x == 0 && y == m) break;
                if(y == m) d = 2;
                else d = 0;
            } else if(d == 2) {
                for(int p : mainD[y - x + OFF]) {
                    if(~ans[p]) continue;
                    ans[p] = T + abs(ps[p].x - x);
                }
                step = min(x, y);

                x -= step; y -= step;
                if(x == 0 && y == 0) break;
                if(x == 0) d = 3;
                else d = 1;
            } else {
                for(int p : viceD[y + x]) {
                    if(~ans[p]) continue;
                    ans[p] = T + abs(ps[p].x - x);
                }
                step = min(n - x, y);

                x += step; y -= step;
                if(x == n && y == 0) break;
                if(y == 0) d = 0;
                else d = 2;
            }

            T += step;
            if(s.count({x, y})) break;
            s.insert({x, y});
        }

        for(int i = 1; i <= K; ++i)
            printf("%I64d\n", ans[i]);
//      puts("");
    }

    return 0;
}
