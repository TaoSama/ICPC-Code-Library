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

int x1, y1, x2, y2;
int getHeight(int x) {
    int same = !((x & 1) ^ (y1 & 1)); //same parity
    return (y2 - y1 - same + 1) / 2 + same;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//  wrong comprehension
//  long long ans = 1LL * (x2 - x1 + 2) / 2 * getHeight(x1);
//  if(x1 + 1 <= x2) ans += 1LL * (x2 - x1 + 1) / 2 * getHeight(x1 + 1);

    long long ans = 1LL * ((y2 - y1) / 2 + 1) * (x2 - x1 + 1) - (x2 - x1) / 2;
    printf("%I64d\n", ans);
    return 0;
}