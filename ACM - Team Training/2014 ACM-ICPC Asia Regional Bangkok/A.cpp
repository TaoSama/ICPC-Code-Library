//
//  Created by TaoSama on 2015-12-11
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 3e4, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int f[N];
bitset<N * N> vis;
void gao() {
    for(int i = 1; i <= 3e4; ++i) {
        f[i] = f[i - 1];
        for(int j = 1; j <= i; ++j) {
            int cur = i * j - 1;
            if(!vis[cur]) {
                ++f[i];
                vis[cur] = 1;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        int n; scanf("%d", &n);
        printf("%d\n", f[n] + 1);
    }
    return 0;
}
