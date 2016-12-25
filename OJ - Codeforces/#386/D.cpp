//
//  Created by TaoSama on 2016-12-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n, k, a, b;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &k, &a, &b) == 4) {
        char c[] = "GB";
        if(a < b) swap(a, b), swap(c[0], c[1]);
        int aCnt = (a + k - 1) / k;
        if(b < aCnt - 1) { puts("NO"); continue;}
        int bEach = b / aCnt, more = b % aCnt;
        while(a > 0 || b > 0) {
            if(a) {
                for(int i = 1; i <= min(a, k); ++i) putchar(c[0]);
                a -= min(a, k);
            }
            if(b) {
                for(int i = 1; i <= bEach; ++i) putchar(c[1]);
                b -= bEach;
                if(more) --b, --more, putchar(c[1]);
            }
        }
        puts("");

    }

    return 0;
}
