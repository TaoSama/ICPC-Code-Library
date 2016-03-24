//
//  Created by TaoSama on 2015-08-11
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int s, n;
vector<int> v[15];
bool dp[15][1005];

bool isOptimal(int t, int idx) {
    if(v[t].size() < v[idx].size()) return true;
    else if(v[t].size() == v[idx].size()) {
        for(int i = (int)v[t].size() - 1; i >= 0; --i) {
            if(v[t][i] != v[idx][i]) return v[t][i] < v[idx][i];
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &s, &n) == 2 && s) {
        for(int i = 1; i <= n; ++i) {
            v[i].clear();
            int k; scanf("%d", &k);
            for(int j = 1; j <= k; ++j) {
                int x; scanf("%d", &x);
                v[i].push_back(x);
            }
        }

        int ans = -INF, idx;
        for(int t = 1; t <= n; ++t) {
            memset(dp, false, sizeof dp);
            dp[0][0] = true;

            for(int i = 1; i <= 1000; ++i) {
                for(int j = 0; j < v[t].size(); ++j) {
                    int w = v[t][j];
                    for(int k = 1; w <= i && k <= s; ++k)
                        dp[k][i] |= dp[k - 1][i - w];
                }
            }

            for(int j = 1; j <= 1000; ++j) {
                bool ok = false;
                for(int i = 1; i <= s; ++i) {
                    if(dp[i][j]) {
                        ok = true;
                        break;
                    }
                }
                if(!ok) {
                    int cur = j - 1;
//                    prln(cur);
                    if(cur > ans || cur == ans && isOptimal(t, idx)) {
                        ans = cur;
                        idx = t;
                    }
                    break;
                }
            }
        }
        printf("max coverage = %3d :", ans);
        for(int i = 0; i < v[idx].size(); ++i)
            printf("%3d", v[idx][i]);
        printf("\n");
    }
    return 0;
}
