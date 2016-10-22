//
//  Created by TaoSama on 2016-10-05
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[N], b[N], c[N];
int pa[N], pb[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        pa[a[i]] = i;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        pb[b[i]] = i;
    }

    int filled = 0;
    memset(c, -1, sizeof c);
    for(int d = 2 * n - 1; filled != n; --d) {
        for(int i = n - 1; ~i; --i) {
            int j = d - i;
            if(j < 0) continue;
            if(j >= n) break;
            int x = pa[i], y = pb[j];
            if(c[(x + y) % n] == -1) {
                c[(x + y) % n] = d;
                if(++filled == n) break;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d%c", c[i], " \n"[i + 1 == n]);

    return 0;
}
