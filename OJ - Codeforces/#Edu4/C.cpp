//
//  Created by TaoSama on 2015-12-26
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

char s[N], stk[N];

bool isLeft(char c) {
    return c == '<' || c == '{' || c == '[' || c == '(';
}

bool isEqual(char x, char y) {
//  printf("%c %c\n", x, y);
    return x == '<'  && y == '>' || x == '{' && y == '}'
           || x == '[' && y == ']' || x == '(' && y == ')';
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        int ans = 0, top = 0;
        bool can = true;
        for(int i = 0; s[i]; ++i) {
            if(isLeft(s[i])) stk[++top] = s[i];
            else {
                if(!top) {can = false; break;}
                ans += !isEqual(stk[top--], s[i]);
            }
        }
        if(can && !top) printf("%d\n", ans);
        else puts("Impossible");
    }
    return 0;
}
