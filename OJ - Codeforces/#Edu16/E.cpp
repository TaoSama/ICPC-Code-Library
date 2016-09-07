//
//  Created by TaoSama on 2016-08-22
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
const int N = 2e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, x, y;
LL f[N];
bool in[N];

LL spfa() {
    deque<int> q; q.push_back(0);
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    in[0] = true;
    while(q.size()) {
        int u = q.front(); q.pop_front();
        in[u] = false;

        int d[] = { -1, 1, u}, c[] = {x, x, y};
        for(int i = 0; i < 3; ++i) {
            int v = u + d[i];
            if(v < 0 || v >= N) continue;
            if(f[v] > f[u] + c[i]) {
                f[v] = f[u] + c[i];
                if(!in[v]) {
                    if(q.size() && f[v] < f[q.front()])
                        q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
    return f[n];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &x, &y) == 3) {
        printf("%I64d\n", spfa());
    }

    return 0;
}
