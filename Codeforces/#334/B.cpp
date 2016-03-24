//
//  Created by TaoSama on 2015-12-01
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

int n, k;
int a[N];

bool check(int x) {
    int l = 1, r = n, cnt = 0;
    while(l <= r) {
        if(a[r] > x) return false;
        if(l != r) {
            if(a[l] + a[r] > x) --r;
            else ++l, --r;
        } else ++l;
        ++cnt;
    }
    return cnt <= k;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int l = 1, r = 1e8;
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m)) r = m - 1;
            else l = m + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
