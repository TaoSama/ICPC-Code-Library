//
//  Created by TaoSama on 2015-07-18
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
bool vis[3005];
int up[3005], v[3005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int cycle, s, g;
        map<int, bool> mp;

        up[0] = n; v[0] = n / m;
        for(g = 1; ; ++g) {
            up[g] = (up[g - 1] - m * v[g - 1]) * 10;
            v[g] = up[g] / m;
//            pr(up[g]); prln(v[g]);
            if(mp[up[g]]) {
                for(s = g - 1; s; --s) {
                    if(up[s] == up[g]) {
                        cycle = g - s;
                        break;
                    }
                }
                break;
            }
            mp[up[g]] = true;
        }

        printf("%d/%d = %d.", n, m, v[0]);
        for(int i = 1; i < s; ++i) printf("%d", v[i]);
        putchar('(');
        for(int i = s; i < g; ++i) {
            if(i > 50) {
                printf("...");
                break;
            }
            printf("%d", v[i]);
        }
        puts(")");
        printf("   %d = number of digits in repeating cycle\n\n", cycle);
    }
    return 0;
}
