//
//  Created by TaoSama on 2015-10-12
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

int n, a[3][55], b[55], ans;
int pre[55], suf[55];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= 2; ++i)
            for(int j = 1; j < n; ++j)
                cin >> a[i][j];
        for(int i = 1; i <= n; ++i) cin >> b[i];
        for(int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + a[1][i];
        }
        suf[n] = 0;
        for(int i = n - 1; i; --i) {
            suf[i] = suf[i + 1] + a[2][i];
        }
        ans = INF;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                int tmp = b[i] + pre[i - 1] + suf[i];
                tmp += b[j] + pre[j - 1] + suf[j];
                ans = min(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
