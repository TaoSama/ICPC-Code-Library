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

int n, m, nxt[N], ex[N];
char a[26], s[N], t[N];

void getNxt(char *t) {
    nxt[0] = m;
    int j = 0;
    while(t[j + 1] && t[j + 1] == t[j]) ++j;
    nxt[1] = j;

    int a = 1, p, L;
    for(int i = 2; i < m; ++i) {
        p = nxt[a] + a - 1, L = nxt[i - a];
        if(i - 1 + L < p) nxt[i] = L;
        else {
            j = max(0, p - i + 1);
            while(t[i + j] && t[i + j] == t[j]) ++j;
            nxt[i] = j;
            a = i;
        }
    }
}

void getEx(char *s, char * t) {
    int j = 0;
    while(s[j] && t[j] && s[j] == t[j]) ++j;
    ex[0] = j;

    int a = 0, p, L;
    for(int i = 1; i < n; ++i) {
        p = ex[a] + a - 1, L = nxt[i - a];
        if(i - 1 + L < p) ex[i] = L;
        else {
            j = max(0, p - i + 1);
            while(s[i + j] && t[j] && s[i + j] == t[j]) ++j;
            ex[i] = j;
            a = i;
        }
    }
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
        getEx(s + m - n, t); //只要可能是明文的部分
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(ex[i] == n - i) {ans = m - (n - i); break;}
        if(ans) s[ans] = t[ans] = 0;
        printf("%s%s\n", s, t);
    }
    return 0;
}
