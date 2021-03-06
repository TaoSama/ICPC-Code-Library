//
//  Created by TaoSama on 2015-08-23
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
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

vector<int> ans;

void dfs(int rt) {
    if(!val[rt]) return;
    ans.push_back(val[rt]);
    dfs(ls[rt]);
    dfs(rs[rt]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        sz = 0; memset(val, 0, sizeof val);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            insert(1, x);
        }
        if(n <= 0) {
            puts("");
            continue;
        }
        ans.clear();
        dfs(1);
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}
