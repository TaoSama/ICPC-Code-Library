//
//  Created by TaoSama on 2015-07-18
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, f[N][10];
void init() {
    for(int i = 1; i <= 10000; ++i) {
        for(int j = 0; j < 10; ++j) f[i][j] = f[i - 1][j];
        int cnt = 0, t = i;
        while(t) {
            f[i][t % 10]++;
            t /= 10;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    init();
    while(t--) {
        cin >> n;
        for(int i = 0; i < 10; ++i) cout << f[n][i] << (i == 9 ? '\n' : ' ');
    }
    return 0;
}
