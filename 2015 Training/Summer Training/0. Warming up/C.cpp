//
//  Created by TaoSama on 2015-07-17
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

int n, w, s;
bool vis[70];
char kid[70][20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) scanf("%s", kid[i]);
        scanf("%d,%d", &w, &s);
        --w;

        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < s; ++j) {
                while(vis[w]) {
                    w++;
                    if(w == n) w -= n;
                }
                w++;
                if(w == n) w -= n;
            }
//          prln(w);
            int last = (w - 1 + n) % n;
            printf("%s\n", kid[last]);
            vis[last] = true;
        }
    }
    return 0;
}
