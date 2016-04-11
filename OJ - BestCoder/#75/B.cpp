//
//  Created by TaoSama on 2016-03-12
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[10], vis[10];

bool isIllegal(int x, int y) {
    if(x > y) swap(x, y);
    if(x == 1 && y == 3 && !vis[2]) return false;
    if(x == 1 && y == 7 && !vis[4]) return false;
    if(x == 3 && y == 9 && !vis[6]) return false;
    if(x == 7 && y == 9 && !vis[8]) return false;
    if(x == 4 && y == 6 && !vis[5]) return false;
    if(x == 2 && y == 8 && !vis[5]) return false;
    if(x == 3 && y == 7 && !vis[5]) return false;
    if(x == 1 && y == 9 && !vis[5]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int ok = n >= 4, last = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(x < 1 || x > 9 || vis[x]) ok = false;
            if(last) ok &= isIllegal(last, x);
            if(x >= 1 && x <= 9) {
                vis[x] = true;
                last = x;
            }
        }
        puts(ok ? "valid" : "invalid");
    }
    return 0;
}
