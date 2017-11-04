//
//  Created by TaoSama on 2017-03-22
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        vector<int> v; v.reserve(n);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", upper_bound(v.begin(), v.end(), r)
                   - lower_bound(v.begin(), v.end(), l));
        }
    }

    return 0;
}
