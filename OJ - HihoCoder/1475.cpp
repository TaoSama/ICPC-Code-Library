//
//  Created by TaoSama on 2017-03-05
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
int f[N];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    map<int, int> mp;
    f[0] = mp[0] = 1;
    int all = 1, s = 0;
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        s += x;
        if(mp.count(s)) {
            add(f[i], all + MOD - mp[s]);
            add(mp[s], f[i]);
        } else {
            f[i] = mp[s] = all;
        }
        add(all, f[i]);
    }
    printf("%d\n", f[n]);

    return 0;
}
