//
//  Created by TaoSama on 2015-09-21
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

int n, a[10];
int dp[8][N];

int encode(int *s, int n) {
    int ret = 0;
    for(int i = 0; i < n; ++i)
        ret = ret * n + s[i];
    return ret;
}

void decode(int *s, int code, int n) {
    for(int i = n - 1; ~i; --i) {
        s[i] = code % n;
        code /= n;
    }
}

int pos[10], top[10];

void bfs(int n) {
    queue<int> q;
    memset(dp[n], -1, sizeof dp[n]);
    for(int i = 0; i < n; ++i) pos[i] = i;
    int s = encode(pos, n);
    q.push(s); dp[n][s] = 0;

    while(q.size()) {
        int u = q.front(); q.pop();
        decode(pos, u, n);
        for(int i = 0; i < n; ++i) top[i] = INF;
        for(int i = 0; i < n; ++i) top[pos[i]] = min(top[pos[i]], i);
        for(int i = 0; i < n; ++i) {
            if(top[i] == INF) continue;
            if(i > 0 && top[i - 1] > top[i]) {
                --pos[top[i]];
                int v = encode(pos, n);
                ++pos[top[i]];
                if(dp[n][v] == -1) {
                    q.push(v);
                    dp[n][v] = dp[n][u] + 1;
                }
            }
            if(i < n - 1 && top[i + 1] > top[i]) {
                ++pos[top[i]];
                int v = encode(pos, n);
                --pos[top[i]];
                if(dp[n][v] == -1) {
                    q.push(v);
                    dp[n][v] = dp[n][u] + 1;
                }
            }
        }
    }
}

bool cmp(int x, int y) {return a[x] < a[y];};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 7; ++i) bfs(i);
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            pos[i] = i;
        }
        sort(pos, pos + n, cmp);
        int s = encode(pos, n);
        printf("%d\n", dp[n][s]);
    }
    return 0;
}
