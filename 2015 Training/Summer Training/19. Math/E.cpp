//
//  Created by TaoSama on 2015-08-14
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
const int N = 3e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cnt[N], sum[N];

void gao() {
    for(int c = 1; c <= 3e7; ++c) {
        for(int a = c + c; a <= 3e7; a += c) {
            int b = a - c;
            if(c == (a ^ b)) cnt[a]++;
        }
    }
    for(int i = 1; i <= 3e7; ++i) sum[i] = sum[i - 1] + cnt[i];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    gao();
    while(t--) {
        int n; scanf("%d", &n);
        printf("Case %d: %d\n" , ++kase, sum[n]);
    }
    return 0;
}
