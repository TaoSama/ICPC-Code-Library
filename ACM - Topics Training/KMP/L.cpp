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
char a[26], s[N], t[N];

void getNxt(char *t) {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < m) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int kmp(char *s, char *t) {
    int i = 0, j = 0;
    while(i < n) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
    }
    return j; //s后缀与t前缀的最大重合长度
}

//s: 密明->明
//t: decode->明X
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s%s", a, s);
        char decode[26];
        for(int i = 0; i < 26; ++i) decode[a[i] - 'a'] = i + 'a';
        for(int i = 0; m = i, s[i]; ++i) t[i] = decode[s[i] - 'a'];
        t[m] = 0;
        n = m >> 1;
        getNxt(t);
        int ans = m - kmp(s + m - n, t);
        if(ans) s[ans] = t[ans] = 0;
        printf("%s%s\n", s, t);
    }
    return 0;
}
