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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, nxt[N];
char s[N];

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < n) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int get(bool isMax = false) {
    int i = 0, j = 1;
    while(i < n && j < n) {
        int k = 0;
        while(k < n && s[i + k] == s[j + k]) ++k;
        if(k == n) break;
        if((s[i + k] < s[j + k]) ^ isMax) j += k + 1;
        else i += k + 1;
        j += i == j;
    }
    return min(i, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        n = strlen(s);
        strncpy(s + n, s, n);
        getNxt();
        int times = n % (n - nxt[n]) ? 1 : n / (n - nxt[n]);
        printf("%d %d %d %d\n", get() + 1, times, get(1) + 1, times);
    }
    return 0;
}
