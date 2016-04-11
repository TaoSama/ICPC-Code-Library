//
//  Created by TaoSama on 2016-03-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, b;
int t[N], d[N];
long long ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &b) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", t + i, d + i);
        long long cur = 0; int nxt = 1, idle = 0;
        queue<int> q;
        while(nxt <= n || q.size()) {
            if(idle) {
                if(q.empty()) q.push(nxt++);
                int p = q.front(); q.pop();
                if(cur < t[p]) cur = t[p];
                cur += d[p];
                ans[p] = cur;
            } else {
                if(q.size() < b) q.push(nxt);
                else ans[nxt] = -1;
                ++nxt;
            }
            if(nxt <= n && cur > t[nxt]) idle = false;
            else idle = true;
        }
        for(int i = 1; i <= n; ++i) printf("%I64d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
