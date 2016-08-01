//
//  Created by TaoSama on 2016-07-30
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, K;
char s[N];
int f[N][26][N];
map<pair<int, int>, int> mp;

void getMax(int& x, int y) {
    if(x < y) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%d", s + 1, &K) == 2) {
        scanf("%d", &n);
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            char a[2], b[2]; int c;
            scanf("%s%s%d", a, b, &c);
            mp[ {*a - 'a', *b - 'a'}] = c;
        }
        n = strlen(s + 1);
        for(int i = 1; i <= n; ++i) s[i] -= 'a';

        memset(f, 0xc0, sizeof f);
        for(int i = 0; i < 26; ++i) {
            if(i == s[1]) f[1][i][0] = 0;
            else f[1][i][1] = 0;
        }
        for(int i = 2; i <= n; ++i) {
            for(int cur = 0; cur < 26; ++cur) {
                for(int j = 0; j <= K; ++j) {
                    for(int lst = 0; lst < 26; ++lst) {
                        bool change = s[i] != cur;
                        getMax(f[i][cur][j + change], f[i - 1][lst][j] + mp[ {lst, cur}]);
//                        if(lst == 0 && cur == 1){
//                          printf("f[%d][%d][%d] = %d\n", i, cur, cur, j + change, f[i][cur][j + change]);
//                        }
                    }
                }
            }
        }

//      for(int i = 1; i <= n; ++i){
//          for(int j = 0; j < 26; ++j){
//              for(int k = 0; k <= K; ++k)
//                  printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
//          }
//      }

        int ans = -INF;
        for(int cur = 0; cur < 26; ++cur)
            for(int j = 0; j <= K; ++j)
                getMax(ans, f[n][cur][j]);
//      prln(f[n][5][0]);
        printf("%d\n", ans);
    }
    return 0;
}
