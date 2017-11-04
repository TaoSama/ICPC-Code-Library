//
//  Created by TaoSama on 2017-02-13
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        if(k == 1) {
            puts("-1");
            continue;
        }

        vector<vector<int>> vis(n, vector<int>(n));
        vector<int> deg(n);
        vector<pair<int, int>> ans;
        for(int delta = 1; delta <= k / 2; ++delta) {
            for(int i = 0; i < n; ++i) {
                int j = (i + delta) % n;
                assert(!vis[i][j]);
                ans.push_back({i, j});
                vis[i][j] = vis[j][i] = true;
                ++deg[i]; ++deg[j];
            }
        }
        if(k & 1) {
            int delta = n / 2, i = 0;
            while(ans.size() != (n * k + 1) / 2) {
                int j = (i + delta) % n;
                assert(!vis[i][j]);
                ans.push_back({i, j});
                vis[i][j] = vis[j][i] = true;
                ++deg[i]; ++deg[j];
                ++i;
            }
        }

        for(int i = 0; i < n; ++i) {
//            printf("%d%c", deg[i], " \n"[i + 1 == n]);
            assert(deg[i] >= k);
        }

        printf("%d\n", ans.size());
        for(const auto& p : ans) printf("%d %d\n", p.first + 1, p.second + 1);
        for(int i = 1; i <= n; ++i) printf("%d%c", i, " \n"[i == n]);
    }

    return 0;
}
