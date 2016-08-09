//
//  Created by TaoSama on 2016-08-04
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int p, q;

int getK(int x) {
    return 31 - __builtin_clz(x + 1);
}

//2^i-1
int dfs(int p, int r, int cur) {
    if(p == q) return cur + r - 1; //last time no rest
    int k = getK(p - q);
    cur += k;
    int to = max(0, p - ((1 << k + 1) - 1)); //jump over
    int ret = cur + 1 + max(q - to, r);
    ret = min(ret, dfs(p - ((1 << k) - 1), r + 1, cur));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &p, &q);
        if(p <= q) printf("%d\n", q - p);
        else printf("%d\n", dfs(p, 0, 0));
    }

    return 0;
}
