//
//  Created by TaoSama on 2016-02-10
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int a[N], R[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = n; i; --i)
        if(a[i] == a[i + 1]) R[i] = R[i + 1];
        else R[i] = i;
    while(q--) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        if(a[l] != x) printf("%d\n", l);
        else {
            if(R[l] + 1 <= r) printf("%d\n", R[l] + 1);
            else puts("-1");
        }
    }
    return 0;
}
