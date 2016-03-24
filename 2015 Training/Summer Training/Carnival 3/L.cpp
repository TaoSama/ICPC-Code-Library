//
//  Created by TaoSama on 2015-08-09
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m, sx, sy;
int k, dx[N], dy[N];

int calc(int &x, int &y, int i) {
    int step = INF;
    if(dx[i] < 0) {
        step = min(step, (1 - x) / dx[i]);
    } else if(dx[i] > 0) {
        step = min(step, (n - x) / dx[i]);
    }

//  pr(i); pr(step);

    if(dy[i] < 0) {
        step = min(step, (1 - y) / dy[i]);
    } else if(dy[i] > 0) {
        step = min(step, (m - y) / dy[i]);
    }

//  prln(step);

    x += step * dx[i];
    y += step * dy[i];
    return step;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> sx >> sy >> k) {
        long long ans = 0;
        for(int i = 1; i <= k; ++i) {
            cin >> dx[i] >> dy[i];
            ans += calc(sx, sy, i);
        }
        cout << ans << '\n';
    }
    return 0;
}
