//
//
//
//  Created by TaoSama on 2015-04-22
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, y;
struct ACM {
    int id, k, x;
    double f;
} a[1005];

bool cmpId(const ACM& x, const ACM& y) {
    return x.id < y.id;
}

bool cmpFact(const ACM& x, const ACM& y) {
    return x.f < y.f;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> y;
    int left = m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].x;
        a[i].id = i;
        a[i].k = m * a[i].x / y;
        left -= a[i].k;
        a[i].f = abs(a[i].x * 1.0 / y - (a[i].k + 1.0) / m) -
                 abs(a[i].x * 1.0 / y - (a[i].k + 0.0)/ m);
    }
    sort(a + 1, a + 1 + n, cmpFact);
    for(int i = 1; i <= left; ++i)
        a[i].k ++;
    sort(a + 1, a + 1 + n, cmpId);
    for(int i = 1; i <= n; ++i) {
        if(i != n) cout << a[i].k << ' ';
        else cout << a[i].k << '\n';
    }

    return 0;
}
