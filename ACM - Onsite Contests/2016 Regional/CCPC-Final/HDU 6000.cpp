//
//  Created by TaoSama on 2016-12-23
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int l, n, m;
typedef long long LL;
struct Node {
    LL t, x;
    bool operator<(const Node& r) const {
        return t + x > r.t + r.x;
    }
};

vector<LL> solve(int n) {
    priority_queue<Node> q;
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        q.push({0, x});
    }
    vector<LL> ret(l);
    for(int i = 0; i < l; ++i) {
        LL& cur = ret[i];
        Node u = q.top(); q.pop();
        u.t += u.x;
        cur = u.t;
        q.push(u);
    }
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
        scanf("%d%d%d", &l, &n, &m);
        auto washers = solve(n);
        auto dryers = solve(m);
        LL ans = 0;
        for(int i = 0; i < l; ++i)
            ans = max(ans, washers[i] + dryers[l - i - 1]);
        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
