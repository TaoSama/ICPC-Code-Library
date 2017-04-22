//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int c[N], cnt;
void dfs(int dep, int sum) {
    if(sum > n) return;
    if(sum == n) {
        ++cnt;
        printf("%d=%d", n, c[0]);
        for(int i = 1; i < dep; ++i) printf("+%d", c[i]);
        putchar(";\n"[dep == 1 || cnt % 4 == 0]);
        return;
    }
    for(int i = !dep ? 1 : c[dep - 1]; i <= n; ++i) {
        c[dep] = i;
        dfs(dep + 1, sum + i);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    dfs(0, 0);

    return 0;
}
