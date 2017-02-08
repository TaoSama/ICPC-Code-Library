//
//  Created by TaoSama on 2017-02-08
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[26];
char s[N];
int f[N][3];
bool valid[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> (s + 1)) {
        for(int i = 0; i < 26; ++i) cin >> c[i];

        for(int i = 1; i <= n; ++i) {
            vector<int> cnt(26, 0);
            bool ok = true;
            for(int j = i; j <= n; ++j) {
                int t = s[j] - 'a';
                cnt[t] = 1;
                for(int k = 0; k < 26 && ok; ++k) {
                    if(cnt[k] && j - i + 1 > c[k]) ok = false;
                }
                valid[i][j] = ok;
//                printf("valid[%d][%d] = %d\n", i,j, valid[i][j]);
            }
        }
        for(int i = 0; i <= n; ++i) {
            f[i][0] = 0;
            f[i][1] = -INF;
            f[i][2] = INF;
        }
        f[0][0] = 1; f[0][2] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(valid[j][i]) {
                    f[i][0] += f[j - 1][0];
                    if(f[i][0] >= MOD) f[i][0] -= MOD;
                    f[i][1] = max({f[i][1], f[j - 1][1], i - j + 1});
                    f[i][2] = min(f[i][2], f[j - 1][2] + 1);
                }
            }
        }
        for(int i = 0; i < 3; ++i) cout << f[n][i] << endl;
    }

    return 0;
}
