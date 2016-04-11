//
//  Created by TaoSama on 2016-01-15
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
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N], t[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int cnt = 0, have = 0, zero = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            int m = strlen(s), one = 0;
            for(int j = 0; j < m; ++j) {
                if(s[j] == '1' && ++one > 1) break;
                else if(s[j] > '1') one = 2;
            }
            if(m == 1 && *s == '0') zero = 1;
            if(one > 1) {memcpy(t, s, sizeof s); have = 1;}
            else cnt += m - 1;
        }
        if(zero) puts("0");
        else {
            if(have) printf("%s", t);
            else putchar('1');
            for(int i = 1; i <= cnt; ++i) putchar('0');
            puts("");
        }
    }
    return 0;
}
