//
//  Created by TaoSama on 2016-02-23
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

int l[10];
double base, height;

void get(int n) {
    double theta = 2 * acos(-1) / n;
    double OC = 0.5 * l[n] / sin(theta / 2);
    base = n * (0.5 * OC * OC * sin(theta));
    height = sqrt(l[n] * l[n] - OC * OC);
}

for(int i = 3; i <= 5; ++i) scanf("%d", l + i);
double ans = 0;
for(int i = 3; i <= 5; ++i) {
    get(i);
    ans += base * height / 3;
}
printf("%.12f\n", ans);

