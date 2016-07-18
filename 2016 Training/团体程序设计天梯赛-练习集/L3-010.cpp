//
//  Created by TaoSama on 2016-07-16
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

int n, rt;
map<int, int> ls, rs;

void insert(int rt, int x) {
    if(x > rt) {
        if(ls.count(rt)) insert(ls[rt], x);
        else ls[rt] = x;
    } else {
        if(rs.count(rt)) insert(rs[rt], x);
        else rs[rt] = x;
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
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        if(i == 1) rt = x;
        else insert(rt, x);
    }

    bool ok = true;
    vector<int> ans;
    queue<pair<int, int> > q; q.push({rt, 1});
    while(q.size()) {
        int u, id; tie(u, id) = q.front(); q.pop();
        ok &= id <= n;
        ans.push_back(u);
        if(ls.count(u)) q.push({ls[u], id << 1});
        if(rs.count(u)) q.push({rs[u], id << 1 | 1});
    }
    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    puts(ok ? "YES" : "NO");

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
