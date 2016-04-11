//
//  Created by TaoSama on 2015-10-01
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
const int N = 5e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int H = 107;

char s[N], t[N];
int stk[N], top;

typedef long long LL;
LL h[N];

int main() {
#ifdef LOCAL
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", t, s) == 2) {
        int n = strlen(s), m = strlen(t);
        LL power = 1, target = 0;
        for(int i = 0; i < m; ++i) {
            power = power * H % MOD;
            target = (target * H % MOD + t[i]) % MOD;
        }

        top = 0;
        for(int i = 0; i < n; ++i) {
            stk[++top] = s[i];
            h[top] = (h[top - 1] * H % MOD + stk[top]) % MOD;
            while(top >= m) {
                LL cur = (h[top] - power * h[top - m] % MOD + MOD) % MOD;
                if(cur == target) top -= m;
                else break;
            }
        }
        for(int i = 1; i <= top; ++i) putchar(stk[i]);
        puts("");
    }
    return 0;
}
