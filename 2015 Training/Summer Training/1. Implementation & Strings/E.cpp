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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int f[N];
void init() {
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= 1e5; ++i) {
        int t = i, sum = i;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        f[sum] = min(f[sum], i);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    init();
    while(t--) {
        int x; scanf("%d", &x);
        if(f[x] == INF) puts("0");
        else printf("%d\n", f[x]);
    }
    return 0;
}
