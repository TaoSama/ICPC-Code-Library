//
//  Created by TaoSama on 2015-08-15
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

const double g = 9.81;
double k, l, s, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lf%lf%lf%lf", &k, &l, &s, &m) == 4) {
        if(k + l + s + m == 0) break;

        double v, delta = (m * g + sqrt(m * m * g * g + 2 * k * l * m * g)) / k;
        if(s > l + delta) puts("Stuck in the air.");
        else {
            if(s <= l) v = sqrt(2 * g * s);
            else v = sqrt(2 * g * s - k * (s - l) * (s - l) / m);
            puts(v > 10 ? "Killed by the impact." : "James Bond survives.");
        }
    }
    return 0;
}
