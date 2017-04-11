//
//  Created by TaoSama on 2017-04-02
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char a[27];
int f[1 << 6];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, a);
        for(int i = 0; i < 26; ++i) a[i] -= 'a';

        map<int, int> mp;
        for(int i = 0; i < 26; ++i) {
            int cnt = 1;
            for(int j = a[i]; j != i; j = a[j]) ++cnt;
            ++mp[cnt];
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        auto add = [&](int& x, int y) {if((x += y) >= MOD) x -= MOD;};
        auto quickPow = [&](int x, int y) {
            int ret = 1;
            for(; y; y >>= 1) {
                if(y & 1) ret = 1LL * ret * x % MOD;
                x = 1LL * x * x % MOD;
            }
            return ret;
        };

        int ans = 0;
        for(int s = 1; s < 1 << v.size(); ++s) {
            int sum = 0, lcm = 1;
            for(int i = 0; i < v.size(); ++i) {
                if(s >> i & 1) {
                    lcm = lcm / __gcd(lcm, v[i].first) * v[i].first;
                    sum += v[i].second;
                }
            }
            f[s] = quickPow(sum, n);
            for(int s0 = s & (s - 1); s0; s0 = (s0 - 1) & s) add(f[s], MOD - f[s0]);
            add(ans, 1LL * f[s] * lcm % MOD);
        }
        printf("%d\n", ans);
    }

    return 0;
}
