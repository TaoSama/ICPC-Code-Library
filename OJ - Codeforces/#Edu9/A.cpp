//
//  Created by TaoSama on 2016-03-01
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

int n, p;
typedef long long LL;
char s[45][100];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &p) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        LL tot = 1;
        for(int i = n - 1; i; --i) {
            if(s[i][5] == 'p') tot = tot * 2 + 1;
            else tot *= 2;
        }
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans += p * (tot / 2);
            if(s[i][5] == 'p') ans += p / 2;
            tot /= 2;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
