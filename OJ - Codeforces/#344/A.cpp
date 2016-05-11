//
//  Created by TaoSama on 2016-03-04
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

unsigned int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%u", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%u", &x);
            a[i] = a[i - 1] | x;
        }
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%u", &x);
            b[i] = b[i - 1] | x;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                int tmp = (a[j] | a[i - 1]) + (b[j] | b[i - 1]);
                ans = max(ans, tmp);
            }
        }
        printf("%u\n", ans);
    }
    return 0;
}
