//
//  Created by TaoSama on 2015-09-07
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int dp[N], pre[N];
char ans[N];

void print(int u) {
    if(~u) {
        print(pre[u]);
        putchar(ans[u]);
    }
}

void bfs() {
    queue<int> q; q.push(1);
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0; pre[1] = -1; ans[1] = '1';
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < 2; ++i) {
            int v = (u * 10 + i) % n;
            if(dp[v] == INF) {
                dp[v] = dp[u] + 1;
                pre[v] = u; ans[v] = '0' + i;
                if(v == 0) {
                    print(0); puts("");
                    return;
                }
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        if(n == 1) {puts("1"); continue;}
        bfs();
    }
    return 0;
}
