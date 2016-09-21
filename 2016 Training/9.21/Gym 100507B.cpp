//
//  Created by TaoSama on 2016-09-17
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
vector<int> G[N];
int val[N], f[N];

void bfs() {
    queue<int> q; q.push(1);
    memset(f, -1, sizeof f);
    f[1] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        int after = val[u] ? val[u] : f[u];
        for(int v : G[u]) {
            if(f[v] == -1) {
                f[v] = after;
                q.push(v);
            } else if(f[v] >= 0 && f[v] != after) {
                f[v] = -2;
                q.push(v);
            }
        }
    }
}

void go(int x) {
    if(f[x] == 0) {
        printf("sober ");
        if(val[x]) printf("%d\n", val[x]);
        else printf("sober\n");
    } else if(f[x] == -2) {
        printf("unknown ");
        if(val[x]) printf("%d\n", val[x]);
        else printf("unknown\n");
    } else {
        printf("%d ", f[x]);
        if(val[x]) printf("%d\n", val[x]);
        else printf("%d\n", f[x]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", val + i);
        int k; scanf("%d", &k);
        while(k--) {
            int x; scanf("%d", &x);
            G[i].push_back(x);
        }
    }
    bfs();
    for(int i = 1; i <= n; ++i) go(i);

    return 0;
}
