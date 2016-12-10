//
//  Created by TaoSama on 2016-10-29
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1000 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, s;

vector<int> G[N];
bool vis[N];
int match[N];

bool dfs(int u) {
    for(int v : G[u]) {
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool hungary(int n) {
    int matches = 0;
    memset(match, -1, sizeof match);
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        matches += dfs(i);
    }
    return matches == n;
}

//const int C = 1e9 + 10;
//bitset<C> b;
//void gao() {
//    int ans = 0, last = 0;
//    for(int i = 2; i < C; ++i) {
//        if(b[i]) continue;
//        ans = max(ans, i - last);
//        last = i;
//        for(int j = i + i; j < C; j += i) b[j] = 1;
//    }
//    printf("%d\n", ans);
//}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    gao(); //282

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &s);
        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(s > 282 * 2 && n > 282 * 2) { puts("No"); continue;}
        for(int i = 1; i < N; ++i) G[i].clear();
        if(n <= 282 * 2) {
            for(int i = 1; i <= n; ++i) {
                for(int p = 1; p <= n; ++p) {
                    if((s + i) % p == 0)
                        G[i].push_back(p);
                }
            }
            puts(hungary(n) ? "Yes" : "No");
        } else {
            for(int i = 1; i <= s; ++i) {
                for(int p = 1; p <= s; ++p) {
                    if((n + i) % p == 0)
                        G[i].push_back(p);
                }
            }
            puts(hungary(s) ? "Yes" : "No");
        }
    }
    return 0;
}
