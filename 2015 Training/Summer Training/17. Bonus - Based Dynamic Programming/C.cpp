//
//  Created by TaoSama on 2015-08-08
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

int n, a[10005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        bool neg = true;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if(a[i] >= 0) neg = false;
        }

        int sum = 0, ans = -INF, tmp = 0, st, ed;
        for(int i = 1; i <= n; ++i) {
            sum += a[i];
            if(sum > ans) {
                ans = sum;
                st = tmp + 1;
                ed = i;
            }
            if(sum < 0) {
                sum = 0;
                tmp = i;
            }
        }
        if(neg) printf("0 %d %d\n", a[1], a[n]);
        else printf("%d %d %d\n", ans, a[st], a[ed]);
    }
    return 0;
}
