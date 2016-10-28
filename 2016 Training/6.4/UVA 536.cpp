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
const int N = 26 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char in[N], pre[N];
int ls[N], rs[N];

int build(int inL, int inR, int preL, int preR) {
    if(inL > inR) return -1;
    int rt = pre[preL] - 'A';
    int p = find(in + inL, in + inR + 1, pre[preL]) - in;
    int sz = p - inL; //左子树大小
    ls[rt] = build(inL, p - 1, preL + 1, preL + sz);
    rs[rt] = build(p + 1, inR, preL + sz + 1, preR);
    return rt;
}

void dfs(int rt) {
    if(rt == -1) return;
    dfs(ls[rt]);
    dfs(rs[rt]);
    putchar(rt + 'A');
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%s%s", pre + 1, in + 1) == 2) {
        int n = strlen(pre + 1);
        int rt = build(1, n, 1, n);
        dfs(rt);
        puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
