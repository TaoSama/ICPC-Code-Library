//
//  Created by TaoSama on 2016-09-18
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

namespace Lehmer {
    const int C = 1e6 + 5, N = C / 10, X = 2e2, Y = 5e4;
    bool isp[C]; int cnt[C], np, pr[N], phi[X][Y];

    void init() {
        for(int i = 2; i < C; i++) {
            if(!isp[i]) pr[np++] = i;
            for(int j = 0; j < np && i * pr[j] < C; j++) {
                isp[i * pr[j]] = 1;
                if(i % pr[j] == 0) break;
            }
            cnt[i] = np;
        }

        // init Phi, https://en.wikipedia.org/wiki/Prime-counting_function
        for(int i = 0; i < X; i++)
            for(int j = 0; j < Y; j++)
                if(i == 0) phi[0][j] = j;
                else phi[i][j] = phi[i - 1][j] - phi[i - 1][j / pr[i - 1]];
    }

    LL Phi(int n, LL m) {
        if(n == 0) return m;
        if(m <= pr[n - 1]) return 1;
        if(n < X && m < Y) return phi[n][m];
        return Phi(n - 1, m) - Phi(n - 1, m / pr[n - 1]);
    }

    LL Pi(LL x) {
        if(x < C) return cnt[x];
        int l = cbrt(x + 0.5), r = sqrt(x + 0.5), n = cnt[l];
        LL res = Phi(n, x) + n - 1;
        for(int i = n; pr[i] <= r; i++) res -= Pi(x / pr[i]) - Pi(pr[i]) + 1;
        return res;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    Lehmer::init();

    LL n;
    while(cin >> n) {
        cout << Lehmer::Pi(n) << endl;
    }

    return 0;
}
