//
//  Created by TaoSama on 2015-10-30
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

int n, m, nxt[N];
char s[N];

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < n) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        m = strlen(s);
        scanf("%s", s + m);
        n = strlen(s);
        m = min(m, n - m);

        getNxt();
        int ans = 0;
        for(int i = nxt[n]; i; i = nxt[i])
            if(i <= m) {ans = i; break;}
        if(ans) {
            s[ans] = 0;
            printf("%s %d\n", s, ans);
        } else puts("0");
    }
    return 0;
}
