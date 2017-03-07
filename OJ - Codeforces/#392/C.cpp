//
//  Created by TaoSama on 2017-01-19
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

int n, m, x, y;
long long k;


//101010101010101
//50505050505051 50505050505051

void count(vector<vector<long long> >& v, int times) {
    int x = 0, y = 0, delta = 1;
    while(times--) {
        v[x][y]++;
        ++y;
        if(y == m) {
            x += delta, y = 0;
            if(x == n) {
                delta = -1;
                x = n - 2;
                y = 0;
            }
        }
//        pr(x); prln(y);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> k >> x >> y) {
        long long maxv, minv, times;
        if(n < 3) {
            int sz = n * m;
            maxv = (k + sz - 1) / sz;
            minv = k / sz;
            times = k % sz >= (x * y) ? maxv : minv;
        } else {
            vector<vector<long long> > v(n, vector<long long>(m, 0));
            vector<vector<long long> > v2(n, vector<long long>(m, 0));

            int sz = (2 * n - 2) * m;
//            prln(sz);
            long long cycle = k / sz;
//            prln(cycle);

            count(v, sz);
            count(v2, k % sz);

            maxv = -2e18;
            minv = 2e18;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    long long val = v[i][j] * cycle + v2[i][j];
                    maxv = max(maxv, val);
                    minv = min(minv, val);
                    if(i + 1 == x && j + 1 == y) times = val;
                }
            }
        }
        cout << maxv << ' ' << minv << ' '  << times << endl;

    }

    return 0;
}
