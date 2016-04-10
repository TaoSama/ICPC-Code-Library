//
//  Created by TaoSama on 2016-03-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, c;
int p[55], t[66];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; ++i) scanf("%d", p + i);
    for(int i = 1; i <= n; ++i) scanf("%d", t + i);

    int a = 0, b = 0, e = 0, f = 0;
    for(int i = 1; i <= n; ++i) {
        e += t[i]; f += t[n - i + 1];
        a += max(0, p[i] - c * e);
        b += max(0, p[n - i + 1] - c * f);
    }

    if(a > b) puts("Limak");
    else if(a < b) puts("Radewoosh");
    else puts("Tie");
    return 0;
}
