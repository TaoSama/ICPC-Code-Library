//
//  Created by TaoSama on 2015-12-08
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

char s[N], cov[26];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        for(int i = 0; i < 26; ++i) cov[i] = i + 'A';
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            char a, b; scanf(" %c %c", &a, &b);
            for(int j = 0; j < 26; ++j)
                if(cov[j] == b) cov[j] = a;
        }
        for(int i = 0; s[i]; ++i) {
            if(isupper(s[i]))
                s[i] = cov[s[i] - 'A'];
            putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
