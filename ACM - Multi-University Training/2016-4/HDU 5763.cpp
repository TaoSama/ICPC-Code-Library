//
//  Created by TaoSama on 2016-08-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n, m;
char s[N], t[N];
int nxt[N], f[N];

void getNxt() {
    nxt[0] = -1;
    for(int i = 0, j = -1; i < m;) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s%s", s, t);
        n = strlen(s), m = strlen(t);
        getNxt();

        f[0] = 1;
        for(int i = 0, j = 0; i < n;) {
            while(j != -1 && s[i] != t[j]) j = nxt[j];
            ++i, ++j;
            f[i] = f[i - 1];
            if(j == m) {
                if((f[i] += f[i - m]) >= MOD) f[i] -= MOD;
            }
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, f[n]);
    }

    return 0;
}
