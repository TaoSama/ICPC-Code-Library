//
//  Created by TaoSama on 2016-04-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
char s[300][300];
const int OFF = 100;
const char* peo = "O/|\\()";
int d[][2] = {0, 0, 1, -1, 1, 0, 1, 1, 2, -1, 2, 1};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        memset(s, 0, sizeof s);
        scanf("%d%d", &n, &m);
        for(int i = OFF; i < n + OFF; ++i) scanf("%s", s[i] + OFF);
        int ans = 0;
        for(int i = OFF; i < n + OFF; ++i) {
            for(int j = OFF; j < m + OFF; ++j) {
                if(s[i][j] == '.') continue;
                ++ans;
                int idx = strchr(peo, s[i][j]) - peo;
                int x = i - d[idx][0], y = j - d[idx][1];
//                printf("%d:= %d %d %d %d\n", idx, i - OFF, j - OFF, x - OFF, y - OFF);
                for(int k = 0; k < 6; ++k) {
                    int nx = x + d[k][0], ny = y + d[k][1];
                    if(s[nx][ny] == peo[k]) s[nx][ny] = '.';
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
