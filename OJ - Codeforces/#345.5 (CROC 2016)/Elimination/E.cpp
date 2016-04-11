//
//  Created by TaoSama on 2016-03-21
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
string s;
int pre[26], rk[26], f[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> s;
    memset(pre, -1, sizeof pre);
    for(int i = 0; i < s.size(); ++i) pre[s[i] - 'a'] = i;
    for(int i = 0; i < k; ++i) rk[i] = i;
    sort(rk, rk + k, [](int x, int y) {
        return pre[x] < pre[y];
    });
    for(int i = 0; i < n; ++i) {
        int c = rk[i % k];
        s += char(c + 'a');
    }

    memset(pre, -1, sizeof pre);
    for(int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if(~pre[c]) f[i + 1] = (2 * f[i] % MOD - f[pre[c]] + MOD) % MOD;
        else f[i + 1] = (2 * f[i] + 1) % MOD;
        pre[c] = i;
    }
    int ans = (f[s.size()] + 1) % MOD;
    cout << ans << '\n';
    return 0;
}
