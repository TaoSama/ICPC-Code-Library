//
//  Created by TaoSama on 2016-02-16
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

int n, a[N];

using P = pair<int, int>;

void getMax(P& x, P y) {
    if(x.first < y.first) x = y;
    else if(x.first == y.first) {
        if((x.second += y.second) >= MOD)
            x.second -= MOD;
    }
}

struct BIT {
    int n; P b[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) b[i] = P(0, 0);
    }
    void add(int i, P v) {
        for(; i <= n; i += i & -i) getMax(b[i], v);
    }
    P sum(int i) {
        P ret(0, 1);
        for(; i; i -= i & -i) getMax(ret, b[i]);
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
        scanf("%d", a + i);
        xs.push_back(a[i]);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    bit.init(xs.size());

    P ans(0, 0);
    for(int i = 1; i <= n; ++i) {
        int x = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
        P cur = bit.sum(x - 1);
        ++cur.first;
        getMax(ans, cur);
        bit.add(x, cur);
    }
    printf("%d\n", ans.second);

    return 0;
}
