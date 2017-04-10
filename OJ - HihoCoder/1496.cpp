//
//  Created by TaoSama on 2017-04-04
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

int n;
pair<int, int> f[1 << 20];

pair<int, int> operator+(pair<int, int> A, pair<int, int> B) {
    pair<int, int> ret = A;
    if(B.first > ret.first) {
        swap(ret.first, ret.second);
        ret.first = B.first;
    } else if(B.second > ret.second) ret.second = B.second;
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
        scanf("%d", &n);
        for(int i = 0; i < 1 << 20; ++i) f[i] = {0, 0};
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            f[x] = f[x] + make_pair(x, 0);
        }

        for(int i = 0; i < 20; ++i)
            for(int j = 0; j < 1 << 20; ++j)
                if(j >> i & 1) f[j ^ (1 << i)] = f[j ^ (1 << i)] + f[j];

        long long ans = 0;
        for(int i = 0; i < 1 << 20; ++i)
            ans = max(ans, 1LL * i * f[i].first * f[i].second);
        printf("%lld\n", ans);
    }

    return 0;
}
