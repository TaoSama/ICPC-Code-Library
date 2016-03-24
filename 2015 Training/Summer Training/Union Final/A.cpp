//
//  Created by TaoSama on 2015-09-01
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

int a, b;

int getMax(int x) {
    char buf[10]; sprintf(buf, "%d", x);
    return *max_element(buf, buf + strlen(buf)) - '0';
}

int add(int x, int y, int b) {
    char sx[10], sy[10], ans[10];
    sprintf(sx, "%d", x);
    sprintf(sy, "%d", y);

    int carry = 0;
    int n = strlen(sx), m = strlen(sy), k = 0;
    for(int i = n - 1, j = m - 1; ; --i, --j, ++k) {
        if(i < 0 && j < 0 && carry == 0) break;
        int t = (i >= 0 ? sx[i] - '0' : 0) + (j >= 0 ? sy[j] - '0' : 0) + carry;
        carry = t >= b;
    }
    return k;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &a, &b) == 2) {
        int maxd = max(getMax(a), getMax(b));
//      printf("maxd: %d\n", maxd);
        int ans = 0;
        for(int i = maxd + 1; i <= 1000; ++i) {
            int t = add(a, b, i);
//          printf("base: %d len: %d\n", i, t);
            ans = max(ans, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
