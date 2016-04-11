//
//  Created by TaoSama on 2015-06-04
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, b[N]; //record the a[i] - a[i-1], so sum(i) = a[i]

void add(int i, int x) {
    for(; i <= n; i += i & -i) b[i] += x;
}

void update(int x, int y, int v) {
    add(x, v); add(y + 1, -v);
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &q);
    int last = 0;
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        add(i, x - last);
        last = x;
    }
    while(q--) {
        int op, x, y; scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &x, &y);
            update(x, x, y - sum(x));
        } else if(op == 2) {
            scanf("%d", &x);
            update(1, n, x);
        } else {
            scanf("%d", &x);
            printf("%d\n", sum(x));
        }
    }
    return 0;
}
