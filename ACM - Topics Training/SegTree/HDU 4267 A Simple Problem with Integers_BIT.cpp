//
//  Created by TaoSama on 2015-09-30
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, A[N];
int b[11][10][N];

void add(int k, int mod, int i, int v) {
    for(; i <= n; i += i & -i) b[k][mod][i] += v;
}

int sum(int k, int mod, int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[k][mod][i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", A + i);
        scanf("%d", &q);
        memset(b, 0, sizeof b);
        while(q--) {
            int op, a; scanf("%d%d", &op, &a);
            if(op == 1) {
                int b, k, c; scanf("%d%d%d", &b, &k, &c);
                add(k, a % k, a, c);
                add(k, a % k, b + 1, -c);
            } else {
                int ans = A[a];
                for(int k = 1; k <= 10; ++k) ans += sum(k, a % k, a);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
