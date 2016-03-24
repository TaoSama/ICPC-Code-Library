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

char s[100];
double m, e;
double f[10], g[35], maxv[10][35];

void init() {
    f[0] = 0.5;
    double x = 0.5;
    for(int i = 1; i < 10; ++i) {
        x /= 2;
        f[i] = f[i - 1] + x;
    }
    for(int i = 0; i < 10; ++i) f[i] = log10(f[i]);

    for(int i = 1; i <= 30; ++i) g[i] = ((1 << i) - 1) * log10(2.0);

    for(int i = 0; i < 10; ++i)
        for(int j = 1; j <= 30; ++j)
            maxv[i][j] = f[i] + g[j];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(scanf("%s", s) == 1 && strcmp(s, "0e0")) {
        char *p = strchr(s, 'e');
        *p = ' ';
        sscanf(s, "%lf%lf", &m, &e);

        while(m < 1) m *= 10, e -= 1;

        double cur = log10(m) + e;
        for(int i = 0; i < 10; ++i) {
            for(int j = 1; j <= 30; ++j) {
                if(abs(maxv[i][j] - cur) < 1e-5) {
                    printf("%d %d\n", i, j);
                    break;
                }
            }
        }
    }
    return 0;
}
