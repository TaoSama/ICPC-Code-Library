
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
char s[N];
int f[2][N][2];

int getCost(pair<int, int>& p) {
    return (p.first != 1) + (p.second != n);
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d%s", &n, &k, s + 1) == 3) {
        vector<pair<int, int>> v;
        for(int i = 1, j; i <= n; i = j + 1) {
            for(; i <= n && s[i] == '0'; ++i);
            if(i > n) break;
            for(j = i; j + 1 <= n && s[j + 1] == '1'; ++j);
            v.push_back(make_pair(i, j));
        }
        // for(const auto& p : v) cout << p.first << ' ' << p.second << endl;
        int ans = 0;
        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        for(int i = 0; i < v.size(); ++i) {
            memcpy(f[!p], f[p], sizeof f[!p]); 
            int cost = getCost(v[i]), len = v[i].second - v[i].first + 1;
            for(int j = 0; j <= k; ++j) {
                if(j >= cost) {
                    f[!p][j][0] = max(f[!p][j][0], f[p][j - cost][0] + len);
                    f[!p][j][1] = max(f[!p][j][1], f[p][j - cost][1] + len);
                    // printf("f[%d] = f[%d] + %d\n", j, j - cost, len);
                }
                if(cost > 0 && j >= cost - 1) {
                    f[!p][j][1] = max(f[!p][j][1], f[p][j - cost + 1][0] + len);
                    // printf("f[%d] = f[%d] + %d\n", j, j - cost + 1, len);
                }
                // printf("f[%d][%d][%d]=%d\n", i, j, 0, f[!p][j][0]);
                // printf("f[%d][%d][%d]=%d\n", i, j, 1, f[!p][j][1]);
                ans = max(ans, f[!p][j][0]);
                ans = max(ans, f[!p][j][1]);
            }
            p = !p;
        }
        printf("%d\n", ans);
    }
    return 0;
}
