//
//  Created by TaoSama on 2016-03-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, ans[N];
pair<int, int> tmp[N];
vector<pair<int, int> > qs[N];

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i; i -= i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i) ret += b[i];
        return ret;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    vector<int> xs;
    for(int i = 1; i <= n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        xs.push_back(l);
        xs.push_back(r);
        tmp[i] = {l, r};
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    for(int i = 1; i <= n; ++i) {
        int l = tmp[i].first, r = tmp[i].second;
        l = lower_bound(xs.begin(), xs.end(), l) - xs.begin() + 1;
        r = lower_bound(xs.begin(), xs.end(), r) - xs.begin() + 1;
        qs[r].push_back({l, i});
    }

    bit.init(xs.size());
    for(int i = 1; i <= xs.size(); ++i) {
        for(auto& p : qs[i]) {
            ans[p.second] = bit.sum(p.first);
            bit.add(p.first, 1);
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}
