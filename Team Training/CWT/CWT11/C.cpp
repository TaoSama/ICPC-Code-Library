//
//  Created by TaoSama on 2016-02-21
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

char s[N], ans[N];
int n, k, r[N];

bool cmp(int x, int y) {
    return max(abs('a' - s[x]), abs('z' - s[x])) <
           max(abs('a' - s[y]), abs('z' - s[y]));
}

void solve(int i, int a, int d, int& leave) {
    if(leave > a) {
        leave -= a;
        ans[i] = s[i];
    } else {
        if(d > 0) ans[i] = 'a' + leave;
        else ans[i] = 'z' - leave;
        leave = 0;

    }
//  printf("%d: %c %c\n", i, s[i], ans[i]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s", &n, &k, s + 1) == 3) {
        int dif = 0;
        for(int i = 1; i <= n; ++i) dif += max(abs('a' - s[i]), abs('z' - s[i]));
        if(dif < k) {puts("-1"); continue;}
        int leave = dif - k;
        for(int i = 1; i <= n; ++i) r[i] = i;
        sort(r + 1, r + 1 + n, cmp);
        memset(ans, 0, sizeof ans);
        for(int i = n; i; --i) {
            if(!leave) break;
            int j = r[i];
            int a = abs('a' - s[j]), z = abs('z' - s[j]);
            if(a > z) solve(j, a, 1, leave);
            else solve(j, z, -1, leave);
        }
        for(int i = 1; i <= n; ++i) {
            if(ans[i]) putchar(ans[i]);
            else putchar("az"[abs('a' - s[i]) < abs('z' - s[i])]);
        }
        puts("");
    }
    return 0;
}
