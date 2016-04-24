//
//  Created by TaoSama on 2016-04-24
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

typedef long long LL;

int n, m;
char s[15][40];
int a[15];
LL ten[20];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    ten[0] = 1;
    for(int i = 1; i < 20; ++i) ten[i] = ten[i - 1] * 10;
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < m; ++i) scanf("%s%d", s[i], a + i);
        map<LL, int> mp;
        int half = n >> 1, lft = n - half;
        for(int i = 0; i < 1 << half; ++i) {
            bool ok = true;
            LL sum = 0;
            for(int j = 0; j < m; ++j) {
                int cnt = 0;
                for(int k = 0; k < half; ++k)
                    if(s[j][k] - '0' == (i >> k & 1)) ++cnt;
                if(cnt <= a[j]) sum += cnt * ten[j];
                else {
                    ok = false;
                    break;
                }
            }
            if(ok) ++mp[sum];
        }

        LL ans = 0;
        for(int i = 0; i < 1 << lft; ++i) {
            bool ok = true;
            LL sum = 0;
            for(int j = 0; j < m; ++j) {
                int cnt = 0;
                for(int k = 0; k < lft; ++k)
                    if(s[j][half + k] - '0' == (i >> k & 1)) ++cnt;
                if(cnt <= a[j]) sum += (a[j] - cnt) * ten[j];
                else {
                    ok = false;
                    break;
                }
            }
            if(ok) ans += mp[sum];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
