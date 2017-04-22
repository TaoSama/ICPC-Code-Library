//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    map<long long, int> mp;
    for(int i = 1; i <= n; ++i) {
        long long a, b; scanf("%lld%lld", &a, &b);
        ++mp[a]; ++mp[b];
    }
    pair<int, long long> ans = {0, 0};
    for(const auto& p : mp) ans = max(ans, {p.second, -p.first});
    int cnt = 0;
    for(const auto& p : mp) if(p.second == ans.first) ++cnt;
    if(cnt == 1) printf("%lld %d\n", -ans.second, ans.first);
    else printf("%lld %d %d\n", -ans.second, ans.first, cnt);

    return 0;
}
