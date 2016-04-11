//
//  Created by TaoSama on 2016-02-07
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

int n, m;
int nxt[N];
char s[N], t[N];

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < m) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int kmp() {
    int i = 0, j = 0, ret = 0;
    while(i < n) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == m) j = 0, ++ret;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s, t) == 2) {
        n = strlen(s);
        m = strlen(t);
        getNxt();
        printf("%d\n", kmp());
    }
    return 0;
}
