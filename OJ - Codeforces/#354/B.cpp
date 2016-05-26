//
//  Created by TaoSama on 2016-05-25
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

int n, t;
int a[20][20], b[20][20];
const int D = 1 << 10;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &t) == 2) {
        memset(a, 0, sizeof a);
        for(int i = 1; i <= t; ++i) {
            a[1][1] += D;
            queue<pair<int, int> > q;
            q.push({1, 1});
            while(q.size()) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                if(a[x][y] > D) {
                    int delta = a[x][y] - D;
                    a[x][y] -= delta;
                    a[x + 1][y] += delta >> 1;
                    a[x + 1][y + 1] += delta >> 1;
                    if(x + 1 <= n) q.push({x + 1, y});
                    if(x + 1 <= n) q.push({x + 1, y + 1});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                ans += a[i][j] == D;
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
