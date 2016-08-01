//
//  Created by TaoSama on 2015-12-22
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

int n, s, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &s);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int sum = 0, ans = INF;
        for(int l = 1, r = 1; l <= n; ++l) {
            while(r <= n && sum < s) sum += a[r++];
            if(sum >= s) ans = min(ans, r - l);
            sum -= a[l];
        }
        if(ans == INF) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
