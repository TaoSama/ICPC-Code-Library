//
//  Created by TaoSama on 2016-09-10
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

typedef long long LL;
int n;
LL k;
vector<int> G[N];
LL a[N];

struct BIT {
    int sz;
    vector<int> b;
    void init(int n) {
        sz = n;
        b = vector<int>(sz + 5, 0);
    }
    void add(int i, int v) {
        for(; i <= sz; i += i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

vector<LL> xs;

int getIdx(LL x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

void dfs(int u, int fa, int dep, LL& ans) {
    ans += a[u] ? bit.sum(getIdx(k / a[u])) : dep;
    int idx = getIdx(a[u]);
    bit.add(idx, 1);
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u, dep + 1, ans);
    }
    bit.add(idx, -1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%I64d", &n, &k);
        xs.clear();
        xs.push_back(0);
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            xs.push_back(a[i]);
            if(a[i]) xs.push_back(k / a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        vector<int> in(n + 1, 0);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            ++in[v];
        }

        LL ans = 0;
        bit.init(xs.size());
        for(int i = 1; i <= n; ++i) if(!in[i]) dfs(i, 0, 0, ans);
        printf("%I64d\n", ans);
    }

    return 0;
}
