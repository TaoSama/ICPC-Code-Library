//
//  Created by TaoSama on 2015-07-23
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

int sum[N];

void build(int p) {
    int v; cin >> v;
    if(v == -1) return;
    sum[p] += v;
    build(p - 1); build(p + 1);
}

bool read() {
    int x; cin >> x;
    if(x == -1) return false;
    memset(sum, 0, sizeof sum);
    int p = N >> 1;
    sum[p] += x;
    build(p - 1); build(p + 1);
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(read()) {
        int p = 0;
        while(sum[p] == 0) ++p;
        cout << "Case " << ++kase << ":\n" << sum[p++];
        while(sum[p]) cout << ' ' << sum[p++];
        cout << "\n\n";
    }
    return 0;
}
