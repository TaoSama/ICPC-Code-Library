//
//  Created by TaoSama on 2015-06-04
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cstdio>
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

int n, q;
long long b[1005][1005];

void add(int x, int y, int v) {
    for(int i = x; i <= n; i += i & -i)
        for(int j = y; j <= n; j += j & -j)
            b[i][j] += v;
}

int sum(int x, int y) {
    long long ret = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            ret += b[i][j];
    return ret & 1;
}

void update(int x1, int y1, int x2, int y2, int x) {
    add(x1, y1, x); add(x1, y2 + 1, x);
    add(x2 + 1, y1, x); add(x2 + 1, y2 + 1, x);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        if(++kase > 1) puts("");
        scanf("%d%d", &n, &q);
        memset(b, 0, sizeof b);
        char op[5]; int x1, y1, x2, y2;
        while(q--) {
            scanf("%s%d%d", op, &x1, &y1);
            if(op[0] == 'C') {
                scanf("%d%d", &x2, &y2);
                update(x1, y1, x2, y2, 1);
                /*for(int i = 1; i <= n; ++i) {
                    for(int j = 1; j <= n; ++j)
                        cout << sum(i, j) << ' ';
                    cout << endl;
                }*/
            } else printf("%d\n", sum(x1, y1));
        }
    }
    return 0;
}
