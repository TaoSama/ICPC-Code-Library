//
//  Created by TaoSama on 2016-07-19
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

int n, p[N], fa[N];

int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) p[i] = i;

        int root = 0, ans = 0;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", fa + i);
            if(fa[i] == i && !root) root = i;
        }

        for(int i = 1; i <= n; ++i) {
            if(fa[i] == i) {
                if(root == i) continue;
                unite(root, i);
                fa[i] = root;
                ++ans;
            } else {
                if(unite(i, fa[i])) continue;
                if(!root) {
                    root = i;
                    fa[i] = i;
                    ++ans;
                } else {
                    unite(root, i);
                    fa[i] = root;
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i)
            printf("%d%c", fa[i], " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
