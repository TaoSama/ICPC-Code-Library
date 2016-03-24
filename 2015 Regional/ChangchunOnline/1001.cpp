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
const int N = 1.5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
char name[N][205];
int val[N];

struct Query {
    int t, p;
    Query() {}
    Query(int t, int p): t(t), p(p) {}
    bool operator< (const Query& rhs) const {
        return t < rhs.t;
    }
} A[N];

int Q[N];

bool vis[N];
int ans[N];

void solve(int Max) {
    set<pair<int, int> > s;
    int rnk = 0, j = 1;
    for(int i = 1; i <= m; ++i) {
        for(; j <= A[i].t; ++j)
            s.insert(make_pair(val[j], -j));
        for(int k = 1; k <= A[i].p; ++k) {
            if(s.empty()) break;
            auto iter = s.end(); --iter;
            if(vis[++rnk]) {
                ans[rnk] = -iter->second;
//                printf("%d\n", -iter->second);
            }
            if(rnk == Max) return;
            s.erase(iter);
        }
    }
    for(; j <= n; ++j) s.insert(make_pair(val[j], -j));
    while(s.size()) {
        auto iter = s.end(); --iter;
        if(vis[++rnk]) {
            ans[rnk] = -iter->second;
//          printf("%d\n", -iter->second);
        }
        if(rnk == Max) return;
        s.erase(iter);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++i)
            scanf("%s%d", name[i], val + i);
        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            A[i] = Query(x, y);
        }
        sort(A + 1, A + 1 + m);

        int Max = 0;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= q; ++i) {
            scanf("%d", Q + i);
            vis[Q[i]] = true;
            Max = max(Max, Q[i]);
        }
        solve(Max);
        for(int i = 1; i <= q; ++i)
            printf("%s%c", name[ans[Q[i]]], " \n"[i == q]);
    }
    return 0;
}
