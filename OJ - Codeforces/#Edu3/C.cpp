//
//  Created by TaoSama on 2015-12-19
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

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
        }
        sort(a + 1, a + 1 + n);

        int ans = 0, avg = sum / n, delta = sum % n;

        for(int i = n; i; --i) {
            if(a[i] <= avg) break;
            ans += a[i] - avg - (delta ? 1 : 0);
            if(delta) --delta;
        }
        printf("%d\n", ans);
    }
    return 0;
}
