//
//  Created by TaoSama on 2015-10-01
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
const int N = 5e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N], t[N];
int nxt[N], pre[N];

void getNxt(char *s) {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < m) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

char stk[N];
int top;
int h[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", t, s) == 2) {
        n = strlen(s), m = strlen(t);
        getNxt(t);

//        for(int i = 0; i < n; ++i) printf("%3c", s[i]); puts("");
//        for(int i = 0; i < n; ++i) printf("%3d", i); puts("");

        top = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            stk[++top] = s[i];
            while(j > 0 && stk[top] != t[j]) j = nxt[j];
            if(stk[top] == t[j]) ++j;
            if(j == m) {
                top -= m;
                j = pre[top];
            }
            pre[top] = j;
        }
        for(int i = 1; i <= top; ++i) putchar(stk[i]);
        puts("");
    }
    return 0;
}
