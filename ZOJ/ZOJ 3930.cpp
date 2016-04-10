//
//  Created by TaoSama on 2016-04-10
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, idx;
char s[N], tmp[N];

char op[] = "+-*/";
bool isoperator(char c) {
    return c && strchr(op, c);
}

void display(int n, char* tmp) {
    if(n > 1) putchar('(');
    printf("[d%s]", tmp);
    for(int i = 1; i < n; ++i)
        printf(" + [d%s]", tmp);
    if(n > 1) putchar(')');
}

void dfs() {
    while(s[idx] && s[idx] != ')') {
        if(s[idx] == '(') {
            putchar('('); ++idx;
            dfs();
            putchar(')'); ++idx;
        }
        if(isdigit(s[idx])) {
            int l = 0, r = 0;
            while(isdigit(s[idx])) tmp[l++] = s[idx++]; tmp[l] = 0;
            if(s[idx] != 'd') {
                printf("%s", tmp); //just digit
                continue;
            }
            l = 0;
            for(int i = 0; tmp[i]; ++i) l = l * 10 + tmp[i] - '0';

            ++idx; //jump d
            while(isdigit(s[idx])) tmp[r++] = s[idx++];  tmp[r] = 0;
            display(l, tmp);
        }
        if(isoperator(s[idx])) printf(" %c ", s[idx++]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d ", &t);
    while(t--) {
        char buf[2005]; gets(buf);
        n = 0;
        for(int i = 0; buf[i]; ++i) {
            if(isspace(buf[i])) continue;
            if(buf[i] == 'd' && (!s[n] || s[n] && !isdigit(s[n]))) s[++n] = '1';
            s[++n] = buf[i];

        }
        s[n + 1] = 0;

        idx = 1;
        dfs();
        printf(" = [Result]\n");  //puts("");
    }
    return 0;
}
