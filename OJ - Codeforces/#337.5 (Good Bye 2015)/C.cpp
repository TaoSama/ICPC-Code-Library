//
//  Created by TaoSama on 2015-12-30
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

typedef long long LL;
int n, m;
char s[505][505];
LL cnt[505][505], line[505][505][2]; //0- 1|

void see(int i, int j) {
    printf("cnt[%d][%d]:= %I64d\n", i, j, cnt[i][j]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        memset(cnt, 0, sizeof cnt);
        memset(line, 0, sizeof line);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
                line[i][j][0] = line[i][j - 1][0];
                line[i][j][1] = line[i - 1][j][1];
                if(s[i][j] == '#') continue;
                line[i][j][0] += s[i][j - 1] == '.';
                line[i][j][1] += s[i - 1][j] == '.';
                cnt[i][j] += s[i - 1][j] == '.';
                cnt[i][j] += s[i][j - 1] == '.';
            }
        }
//        for(int i = 1; i <= n; ++i)
//            for(int j = 1; j <= m; ++j)
//                printf("cnt[%d][%d]:= %I64d\n", i, j, cnt[i][j]);
        int q; scanf("%d", &q);
        while(q--) {
            int r1, r2, c1, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            LL ans = cnt[r2][c2] + cnt[r1][c1];
//            see(r2, c2); see(r1, c1);
//            see(r1, c2); see(r2, c1);
            ans -= cnt[r1][c2] + cnt[r2][c1];
//            prln(ans);
            ans += line[r1][c2][0] - line[r1][c1 - 1][0];
//            prln(ans);
            ans -= (s[r1][c1] == s[r1][c1 - 1] && s[r1][c1] == '.');
//            prln(ans);
            ans += line[r2][c1][1] - line[r1 - 1][c1][1];
//            prln(ans);
            ans -= (s[r1][c1] == s[r1 - 1][c1] && s[r1][c1] == '.');
            printf("%I64d\n", ans);
        }
//        return 0;
    }
    return 0;
}
