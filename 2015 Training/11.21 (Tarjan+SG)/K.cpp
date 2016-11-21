//
//  Created by TaoSama on 2015-11-21
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
#include <unordered_set>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, s[105];

int sg[10005], mark[10005], kase;

int dfs(int x) {
    int& ret = sg[x];
    if(mark[x] == kase) return ret;
    mark[x] = kase;
    bool vis[105] = {};
    for(int i = 1; i <= n; ++i)
        if(x >= s[i]) vis[dfs(x - s[i])] = true;
        else break;

    for(int i = 0; ; ++i)
        if(!vis[i]) {ret = i; break;}
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        ++kase;
        for(int i = 1; i <= n; ++i) scanf("%d", s + i);
        sort(s + 1, s + 1 + n);
        scanf("%d", &m);
        while(m--) {
            int k; scanf("%d", &k);
            int ans = 0;
            while(k--) {
                int x; scanf("%d", &x);
                ans ^= dfs(x);
            }
            putchar(ans ? 'W' : 'L');
        }
        puts("");
    }
    return 0;
}

