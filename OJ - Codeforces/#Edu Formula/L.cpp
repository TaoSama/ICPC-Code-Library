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

char s[10], t[10];
int d[] = {0, 1, 3, 5, 4, 2};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s", s + 1);
    for(int i = 1; i <= 5; ++i) t[i] = s[d[i]];
    long long x = atoi(t + 1), ans = 1;
    for(int i = 1; i <= 5; ++i)
        ans = ans * x % 100000;
    printf("%05I64d\n", ans);
    return 0;
}
