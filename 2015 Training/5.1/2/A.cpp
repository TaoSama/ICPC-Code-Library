//
//  Created by TaoSama on 2015-06-03
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

double a, b, c, d;
const double EPS = 1e-15;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(0);

    cin >> a >> b >> c >> d;
    double one = (1 - a / b) * (1 - c / d);
    double ans = a / b / (1 - one);
    printf("%.12f\n", ans);
    return 0;
}
