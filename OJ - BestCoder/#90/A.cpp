//
//  Created by TaoSama on 2016-12-17
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

const int _K = 50268147, _B = 6082187, _P = 100000007;
int _X;
inline int get_rand(int _l, int _r) {
    _X = ((long long)_K * _X + _B) % _P;
    return _X % (_r - _l + 1) + _l;
}
int n, m, k, seed;
int x[N], y[N];
int h[N], v[N];
void Init() {
    scanf("%d%d%d%d", &n, &m, &k, &seed);
    _X = seed;
    for (int i = 1; i <= k; ++i) {
        x[i] = get_rand(1, n);
        y[i] = get_rand(1, m);
    }
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        Init();
        memset(h, 0, sizeof h);
        memset(v, 0, sizeof v);
        for(int i = 1; i <= k; ++i) {
            h[x[i]] = 1;
            v[y[i]] = 1;
        }
        int a = 0, b = 0;
        for(int i = 1; i <= n; ++i) a += !h[i];
        for(int i = 1; i <= m; ++i) b += !v[i];
        printf("%d %d\n", a, b);
    }
    return 0;
}
