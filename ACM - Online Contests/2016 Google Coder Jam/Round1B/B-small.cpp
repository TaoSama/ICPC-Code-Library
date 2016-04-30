//
//  Created by TaoSama on 2016-04-30
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

bool check(char* s, char* t) {
    for(int i = 0; t[i]; ++i) {
        if(t[i] == '?') continue;
        if(s[i] != t[i]) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        char a[5], b[5]; scanf("%s%s", a, b);
        int n = strlen(a);
        int L = n == 1 ? 10 : n == 2 ? 100 : 1000;
        int dif = INF, x = -1, y = -1;
        for(int i = 0; i < L; ++i) {
            char aa[5]; sprintf(aa, "%0*d", n, i);
            if(!check(aa, a)) continue;
            for(int j = 0; j < L; ++j) {
                char bb[5]; sprintf(bb, "%0*d", n, j);
                if(!check(bb, b)) continue;

                int tmp = abs(i - j);
                if(tmp < dif) {
                    dif = tmp;
                    x = i; y = j;
                } else if(tmp == dif) {
                    if(i < x) {
                        x = i;
                        y = j;
                    } else if(i == x) {
                        if(j < y) {
                            y = j;
                        }
                    }
                }
            }
        }
        static int kase = 0;
        printf("Case #%d: %0*d %0*d\n", ++kase, n, x, n, y);
    }
    return 0;
}
