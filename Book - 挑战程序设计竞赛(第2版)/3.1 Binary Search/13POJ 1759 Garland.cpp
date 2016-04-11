//
//  Created by TaoSama on 2015-04-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

int n;
double A, B, a[1005];

//h2µÄÖµ
bool check(double x) {
    a[2] = x;
    for(int i = 3; i <= n; ++i) {
        a[i] = 2 * a[i - 1] + 2 - a[i - 2];
        if(a[i] < 0) return false;
    }
    B = a[n];
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%lf", &n, &A);
    a[1] = A;
    double l = -1, r = 1e3 + 1;
    for(int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.2f\n", B);
    return 0;
}
