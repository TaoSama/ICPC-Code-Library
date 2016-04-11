//
//  Created by TaoSama on 2015-05-29
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
const int N = 1 << 17;

int n, m, l;
bool vis[N + 5], a[N + 5];

bool dfs(int k, int v) {
    if(k == l) return true;
    v = (v % m) << 1;
    if(!vis[v] && k <= l - n) {
        vis[v] = true;
        a[k] = 0;
        bool F = dfs(k + 1, v);
        vis[v] = false;
        if(F) return true;
    }
    int w = v + 1;
    if(!vis[w]) {
        vis[w] = true;
        a[k] = 1;
        bool F = dfs(k + 1, w);
        vis[w] = false;
        if(F) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        l = 1 << n; m = l >> 1;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            a[i] = 0;
            a[l - i + 1] = 1;
        }
        vis[0] = vis[(1 << n) - 1] = true;

        dfs(n + 1, 0);
        printf("%d\n", l);
        for(int i = 1; i <= l; ++i)
            printf("%d", a[i]);
        puts("");
    }
    return 0;
}

/*
暴力找规律代码(事实连linux都爆栈 数真大):
//
//  Created by TaoSama on 2015-05-29
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
const int N = 1 << 17;

int n, m, l;
bool vis[N + 5], a[N + 5];

bool dfs(int k, int v) {
    if(k == l + 1) {
        int w = (v % m) << 1, t = w;
        for(int i = 1; i < n; ++i) {
            w += a[i];
            if(vis[w]) {
                for(int j = 1; j <= i; ++j) {
                    t += a[j];
                    vis[t] = false;
                    t = (t % m) << 1;
                }
                return false;
            }
            w = (w % m) << 1;
        }
        return true;
    }
    v = (v % m) << 1;
    for(int i = 0; i <= 1; ++i) {
        int w = v + i;
        if(k >= n && vis[w]) continue;
        a[k] = i;
        if(k >= n) vis[w] = true;
        bool F = dfs(k + 1, w);
        if(k >= n) vis[w] = false;
        if(F) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        l = 1 << n; m = l >> 1;
        memset(vis, false, sizeof vis);

        dfs(1, 0);

        printf("%d\n", l);
        for(int i = 1; i <= l; ++i)
            printf("%d", a[i]);
        puts("");
    }
    return 0;
}
*/
