//
//  Created by TaoSama on 2016-10-08
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
LL c, f[2][N]; //1~i, j vertices in S \ source
LL p[N], s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> c) {
        for(int i = 1; i <= n; ++i) cin >> p[i];
        for(int i = 1; i <= n; ++i) cin >> s[i];

        int q = 0;
        memset(f[q], 0x3f, sizeof f[q]);
        f[q][0] = 0;
        for(int i = 1; i <= n; ++i) {
            memset(f[!q], 0x3f, sizeof f[!q]);
            for(int j = 0; j <= i; ++j) {
                //add i to S, cut i->t
                if(j) f[!q][j] = min(f[!q][j], f[q][j - 1] + s[i]);
                //add i to T, cut s->i, j->i, j < i
                f[!q][j] = min(f[!q][j], f[q][j] + p[i] + c * j);
            }
            q = !q;
        }
        LL ans = 1e18;
        for(int i = 0; i <= n; ++i) ans = min(ans, f[q][i]);
        cout << ans << endl;
    }

    return 0;
}
