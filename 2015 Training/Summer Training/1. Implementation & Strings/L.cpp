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

int n, m, cnt, num[15][15], down[15];
char a[15][15];
int d[][2] = { -1, 0, 0, -1};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &m);
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '*') continue;
                if(i == 1) num[i][j] = ++cnt;
                else {
                    bool lef = false, rig = false;
                    int x = i, y = j - 1;
                    if(x >= 1 && x <= n && y >= 1 && y <= m && isalpha(a[x][y])) lef = true;
                    x = i - 1, y = j;
                    if(x >= 1 && x <= n && y >= 1 && y <= m && isalpha(a[x][y])) rig = true;
                    if(!(lef && rig)) num[i][j] = ++cnt;
                }

            }
        }

        if(kase) puts("");
        printf("puzzle #%d:\nAcross\n", ++kase);

        for(int i = 1; i <= n; ++i) {
            bool first = true, put = false;
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] != '*') {
                    if(first) {
                        first = false;
                        printf("%3d.", num[i][j]);
                    }
                    putchar(a[i][j]);
                    put = true;
                }
                if(a[i][j] == '*' || j == m) {
                    if(put) putchar('\n');
                    put = false;
                    first = true;
                }
            }
        }
        puts("Down");
        memset(down, 0, sizeof down);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1, k; j <= m; ++j) {
                if(i <= down[j] || a[i][j] == '*') continue;
                bool first = true;
                for(k = i; k <= n; ++k) {
                    if(a[k][j] != '*') {
                        if(first) {
                            first = false;
                            printf("%3d.", num[k][j]);
                        }
                        putchar(a[k][j]);
                    } else {
                        putchar('\n');
                        break;
                    }
                    if(k == n) putchar('\n');
                }
                down[j] = k - (a[k][j] == '*');
            }
        }
    }
    return 0;
}
