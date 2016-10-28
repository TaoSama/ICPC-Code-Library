//
//  Created by TaoSama on 2016-06-04
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, in[N], pre[N];
int rt, ls[N], rs[N];

int dfs(int inL, int inR, int preL, int preR) {
    if(inL > inR) return -1;
    int rt = pre[preL];
    int p = find(in + inL, in + inR + 1, rt) - in;
    int cnt = p - inL;
    ls[rt] = dfs(inL, p - 1, preL + 1, preL + cnt);
    rs[rt] = dfs(p + 1, inR, preL + cnt + 1, preR);
    return rt;
}

void bfs() {
    queue<int> q; q.push(rt);
    while(q.size()) {
        int u = q.front(); q.pop();
        if(u == -1) continue;
        if(u != rt) putchar(' ');
        printf("%d", u);
        q.push(rs[u]);
        q.push(ls[u]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", in + i);
    for(int i = 1; i <= n; ++i) scanf("%d", pre + i);

    rt = dfs(1, n, 1, n);
    bfs();
    puts("");

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
