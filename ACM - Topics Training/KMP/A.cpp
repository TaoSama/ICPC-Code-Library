//
//  Created by TaoSama on 2015-10-27
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N], b[N];
int nxt[N];

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < m) {
        if(j == -1 || b[i] == b[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int kmp() {
    int i = 0, j = 0;
    while(i < n) {
        if(j == -1 || a[i] == b[j]) ++i, ++j;
        else j = nxt[j];
        if(j == m) return i - m + 1;
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i = 0; i < m; ++i) scanf("%d", b + i);
        getNxt();
        printf("%d\n", kmp());
    }
    return 0;
}
