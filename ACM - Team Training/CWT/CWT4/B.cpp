//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N];
int c[26];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        scanf("%s", s);
        for(int i = 0; i < 26; ++i) c[i] = i;
        while(m--) {
            char a, b; scanf(" %c %c", &a, &b);
            for(int i = 0; i < 26; ++i) {
                if(a - 'a' == c[i]) c[i] = b - 'a';
                else if(b - 'a' == c[i]) c[i] = a - 'a';
            }
        }
        for(int i = 0; i < n; ++i) s[i] = c[s[i] - 'a'] + 'a';
        puts(s);
    }
    return 0;
}
