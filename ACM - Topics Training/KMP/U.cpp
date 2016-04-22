//
//  Created by TaoSama on 2015-10-31
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[N];
char a[N], s[N];

int manacher() {
    s[0] = '@', s[1] = '#', n = 2;
    for(int i = 0; a[i]; ++i)
        s[n++] = a[i], s[n++] = '#';
    s[n] = 0;
    int mx = 0, id;
    for(int i = 1; i < n; ++i) {
        if(mx > i) p[i] = min(mx - i, p[2 * id - i]);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(mx < p[i] + i) mx = p[i] + i, id = i;
    }
    int ret = 0;
    for(int i = 1; i < n; ++i) ret = max(ret, p[i] - 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%s", a) == 1 && *a != 'E') {
        printf("Case %d: %d\n", ++kase, manacher());
    }
    return 0;
}
