//
//  Created by TaoSama on 2015-12-10
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

int n, m, sx, sy;
char s[N], vis[505][505];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &sx, &sy) == 4) {
        memset(vis, false, sizeof vis);
        scanf("%s", s);
        int l = strlen(s);
        int cnt = vis[sx][sy] = 1;
        printf("1 ");
        for(int i = 0; i < l - 1; ++i) {
            if(s[i] == 'U' && sx - 1 >= 1) --sx;
            if(s[i] == 'D' && sx + 1 <= n) ++sx;
            if(s[i] == 'L' && sy - 1 >= 1) --sy;
            if(s[i] == 'R' && sy + 1 <= m) ++sy;

            printf("%d ", !vis[sx][sy]);
            if(!vis[sx][sy]) ++cnt;
            vis[sx][sy] = true;
        }
        printf("%d\n", n * m - cnt);
    }
    return 0;
}
