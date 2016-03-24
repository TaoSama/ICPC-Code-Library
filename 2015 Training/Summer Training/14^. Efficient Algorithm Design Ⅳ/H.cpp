//
//  Created by TaoSama on 2015-08-04
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool g[305][305];

bool check() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            bool _and = false, _not = false;
            for(int k = 0; k < n; ++k) {
                if(g[i][k] & g[j][k]) _and = true;
                if(g[i][k] ^ g[j][k]) _not = true;
                if(_and && _not) return false;
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(g, false, sizeof g);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            g[u][v] = 1;
        }
        printf("Case #%d: ", ++kase);
        puts(check() ? "Yes" : "No");
    }
    return 0;
}
