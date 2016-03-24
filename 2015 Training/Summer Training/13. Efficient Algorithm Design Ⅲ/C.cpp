//
//  Created by TaoSama on 2015-08-03
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, rnk[N];
double v[N][10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) {
            double buf[3];
            for(int j = 0; j < 3; ++j) scanf("%lf", buf + j);
            for(int j = 0; j < 1 << 3; ++j) {
                double sum = 0;
                for(int k = 0; k < 3; ++k)
                    if(j >> k & 1) sum += buf[k];
                v[i][j] = sum;
            }
            sort(v[i], v[i] + 8);
        }

        bool ok = true;
        double preSco = 1e8;
        int preId = -1;
        for(int i = 1; i <= n; ++i) {
            int curId; scanf("%d", &curId);
            bool can = false;
            for(int j = 7; j >= 0; --j) {
                double curSco = v[curId][j];
                if(curId > preId && abs(curSco - preSco) <= 1e-5 ||
                        curSco < preSco) {
                    preSco = curSco;
                    preId = curId;
                    can = true;
                    break;
                }
            }
            if(!can) ok = false;
        }
        if(ok) printf("Case %d: %.2f\n", ++kase, preSco);
        else printf("Case %d: No solution\n", ++kase);
    }
    return 0;
}
