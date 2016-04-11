//
//  Created by TaoSama on 2016-01-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char a[2][N];
int id[2][N], placed[N], used[N];

int main() {
    freopen("high_security.txt", "r", stdin);
    freopen("high_security_out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < 2; ++i) scanf("%s", a[i] + 1);
        int c = 0;
        memset(id, 0, sizeof id);
        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(a[i][j] == '.') {
                    if(a[i][j - 1] != '.') ++c;
                    id[i][j] = c;
//                    printf("id[%d][%d] = %d\n", i, j, id[i][j]);
                }
            }
        }
        memset(placed, 0, sizeof placed);
        memset(used, 0, sizeof used);

        int u = 1, d = 1;
        while(u <= n || d <= n) {
            while(u <= n && !id[0][u]) ++u; //find first .
            if(u <= n) {
                if(id[0][u] == id[0][u + 1]) placed[id[0][u]] = true;
                else {
                    if(id[1][u]) { //下一层是否必须放置
                        int x = id[1][u];
                        placed[x] |= id[1][u - 1] == x;
                        placed[x] |= id[1][u + 1] == x;
                    }
                    //是否可以使用免费次数
                    if(!placed[id[1][u]] || used[id[1][u]])
                        placed[id[0][u]] = true;
                    else used[id[1][u]] = true;
                }
            }
            while(u <= n && id[0][u]) ++u; //find first X

            while(d <= n && !id[1][d]) ++d; //find first .
            if(d <= n) {
                if(id[1][d] == id[1][d + 1]) placed[id[1][d]] = true;
                else {
                    if(id[0][d]) { //上一层是否必须放置
                        int x = id[0][d];
                        placed[x] |= id[0][d - 1] == x;
                        placed[x] |= id[0][d + 1] == x;
                    }
//                  printf("d: %d up: %d\n", d, placed[id[0][d]]);
                    //是否可以使用免费次数
                    if(!placed[id[0][d]] || used[id[0][d]])
                        placed[id[1][d]] = true;
                    else used[id[0][d]] = true;
                }
            }
            while(d <= n && id[1][d]) ++d; //find first X
        }

        int ans = 0;
//      printf("placed: "); for(int i = 1; i <= c; ++i) if(placed[i]) printf("%d ", i); puts("");
        for(int i = 1; i <= c; ++i) ans += placed[i];
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
