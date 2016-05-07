//
//  Created by TaoSama on 2016-05-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int root, ls[N], rs[N];

bool dfs(int& rt, int l, int r, bool o) {
//    printf("rt = %d range[%d, %d]\n", rt, l, r);
    if(l > r) {
        rt = 0;
        return true;
    }
    rt = l;
    int p = l;
    while(p < r && ((a[p + 1] < a[l]) ^ o)) ++p;
    int q = p;
    while(q < r && ((a[q + 1] >= a[l]) ^ o)) ++q;
//    printf("p = %d q = %d\n", p, q);
    if(q < r) return false;
    return dfs(ls[rt], l + 1, p, o) && dfs(rs[rt], p + 1, r, o);
}

void go(int rt) {
    if(!rt) return;
    go(ls[rt]);
    go(rs[rt]);
    printf("%d%c", a[rt], " \n"[rt == root]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        if(dfs(root, 1, n, 0) || dfs(root, 1, n, 1)) {
            puts("YES");
            go(root);
        } else puts("NO");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
