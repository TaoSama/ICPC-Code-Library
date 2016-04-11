//
//  Created by TaoSama on 2015-11-21
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, f[N], a[N], b[N], wh[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        memset(wh, 0, sizeof wh);
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", f + i);
            if(wh[f[i]]) wh[f[i]] = -1;
            else wh[f[i]] = i;
        }

        bool Ambiguity = false, Impossible = false;
        for(int i = 1; i <= m; ++i) {
            scanf("%d", b + i);
            if(!wh[b[i]]) Impossible = true;
            else if(wh[b[i]] == -1) Ambiguity = true;
            a[i] = wh[b[i]];
        }
        if(Impossible) puts("Impossible");
        else if(Ambiguity) puts("Ambiguity");
        else {
            puts("Possible");
            for(int i = 1; i <= m; ++i)
                printf("%d%c", a[i], " \n"[i == m]);
        }
    }
    return 0;
}
