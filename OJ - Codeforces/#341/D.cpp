//
//  Created by TaoSama on 2016-02-01
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
#include <complex>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

double tx, ty, tz;
long double x, y, z, a[15], e[15];
char s[][10] = {"", "x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x",
                "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"
               };

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lf%lf%lf", &tx, &ty, &tz) == 3) {
        x = tx, y = ty, z = tz;
        e[1] = z * log(y);
        e[2] = y * log(z);
        e[3] = e[4] = log(y * z);
        e[5] = z * log(x);
        e[6] = x * log(z);
        e[7] = e[8] = log(x * z);
        e[9] = y * log(x);
        e[10] = x * log(y);
        e[11] = e[12] = log(x * y);

        for(int i = 1; i <= 4; ++i) a[i] = log(x);
        for(int i = 5; i <= 8; ++i) a[i] = log(y);
        for(int i = 9; i <= 12; ++i) a[i] = log(z);

        bool greaterOne = x > 1 || y > 1 || z > 1;
        int ans = -1;
        if(greaterOne) {
            //find the first >1
            for(int i = 1; i <= 12; ++i) if(a[i] > 0) {ans = i; break;}
            for(int i = 1; i <= 12; ++i) {
                if(a[i] > 0 && log(a[i]) + e[i] > log(a[ans]) + e[ans] + 1e-8)
                    ans = i;
            }
        } else {
            ans = 1;
            //if there is 1, find the first
            for(int i = 1; i <= 12; ++i) if(a[i] == 0) {ans = i; break;}
            for(int i = 1; i <= 12; ++i) a[i] = -a[i];
            for(int i = 1; i <= 12; ++i) {
                if(a[i] > 0 && log(a[i]) + e[i] < log(a[ans]) + e[ans] - 1e-8)
                    ans = i;
            }
        }
        puts(s[ans]);
    }
    return 0;
}
