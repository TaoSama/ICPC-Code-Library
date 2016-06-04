//
//  Created by TaoSama on 2016-05-29
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

int n;
#define MP make_pair

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector<pair<int, int> > e[3];
        for(int i = 1; i <= n; ++i) {
            int x, y, z, d; scanf("%d%d%d%d", &x, &y, &z, &d);
            y -= z; x += z;
            if(y > x) continue;
            int p = d == 1 ? 1 : 2;
            e[p].push_back(MP(y, 1));
            e[p].push_back(MP(x + 1, -1));
        }
        for(int i = 1; i <= 2; ++i) sort(e[i].begin(), e[i].end());
        int ans = 0, cnt = 0, sum = 0, maxv = 0;
        for(int r = 0, l = 0; r < e[2].size(); ++r) {
            sum += e[2][r].second;
            if(r + 1 < e[2].size() &&
                    e[2][r].first == e[2][r + 1].first) continue;
            while(l < e[1].size() && e[1][l].first <= e[2][r].first) {
                cnt += e[1][l++].second;
                maxv = max(maxv, cnt);
            }
            ans = max(ans, sum + maxv);
        }
        static int kase = 0;
        printf("Case #%d:\n%d\n", ++kase, ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
