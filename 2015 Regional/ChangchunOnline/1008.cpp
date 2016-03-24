//
//  Created by TaoSama on 2015-09-13
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int sz, ls[N], rs[N], val[N];

int newNode(int x) {
    ++sz;
    ls[sz] = rs[sz] = 0;
    val[sz] = x;
    return sz;
}

int insert(int rt, int x) {
    if(!val[rt]) return newNode(x);
    if(x < val[rt]) ls[rt] = insert(ls[rt], x);
    else rs[rt] = insert(rs[rt], x);
    return rt;
}

void dfs(int rt, int x) {
    if(x < val[rt]) {
        putchar('E');
        dfs(ls[rt], x);
    } else if(x > val[rt]) {
        putchar('W');
        dfs(rs[rt], x);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        sz = 0;  memset(val, 0, sizeof val);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            insert(1, x);
        }
        scanf("%d", &q);
        while(q--) {
            int x; scanf("%d", &x);
            dfs(1, x);
            puts("");
        }
    }
    return 0;
}
