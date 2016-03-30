//
//  Created by TaoSama on 2016-02-26
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m, q;
int son[N][2], w[N];
vector<pair<int, int> > Q[N];

struct BIT {
    int n, b[N << 1];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i)
            b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
    int getAll() {
        return sum(n);
    }
} bit[2];  //0 for left, 1 for right

vector<int> xs;
pair<int, int> ans[N];

//ans = 1/2 ^ leftLarge  * 1/8 ^ leftSmall;
//    * 1/2 ^ rightLarge * 7/8 ^ rightSmall;

void dfs(int u) {
    int leftAll = bit[0].getAll(), rightAll = bit[1].getAll();
    for(auto p : Q[u]) { //answer queries
        int x = p.first, id = p.second;
        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
        int leftSmall = bit[0].sum(x - 1), leftLarge = leftAll - bit[0].sum(x);
        int rightSmall = bit[1].sum(x - 1), rightLarge = rightAll - bit[1].sum(x);

        //if equal ones exist
        if(leftAll + rightAll - leftSmall - leftLarge - rightSmall - rightLarge) {
            ans[id] = { -1, -1};
            continue;
        }
        ans[id].first = rightSmall;
        ans[id].second = leftLarge + rightLarge + 3 * (leftSmall + rightSmall);
    }

    w[u] = lower_bound(xs.begin(), xs.end(), w[u]) - xs.begin() + 1;
    for(int i = 0; i < 2; ++i) {
        int v = son[u][i];
        if(!v) continue;
        bit[i].add(w[u], 1);  //add before go down
        dfs(v);
        bit[i].add(w[u], -1); //back
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        xs.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", w + i);
            xs.push_back(w[i]);
        }

        scanf("%d", &m);
        memset(son, 0, sizeof son);
        while(m--) {
            int u; scanf("%d", &u);
            for(int i = 0; i < 2; ++i)
                scanf("%d", son[u] + i);
        }
        scanf("%d", &q);
        for(int i = 1; i <= n; ++i) Q[i].clear();
        for(int i = 1; i <= q; ++i) {
            int v, x; scanf("%d%d", &v, &x);
            xs.push_back(x);
            Q[v].push_back({x, i});
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        for(int i = 0; i < 2; ++i) bit[i].init(xs.size());
        dfs(1);
        for(int i = 1; i <= q; ++i)
            if(~ans[i].first) printf("%d %d\n", ans[i].first, ans[i].second);
            else puts("0");
    }
    return 0;
}
