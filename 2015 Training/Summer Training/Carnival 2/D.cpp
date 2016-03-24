//
//  Created by TaoSama on 2015-08-02
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

int n, m;
pair<int, int> a[N];
map<int, long long> mp;

void update(int i, long long v) {
    for(; i <= n + 1; i += i & -i)
        mp[i] = (mp[i] + v) % MOD;
}

long long sum(int i) {
    long long ret = 0;
    for(; i; i -= i & -i) ret = (ret + mp[i]) % MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        mp.clear();
        for(int i = 1; i <= m; ++i) {
            cin >> a[i].second >> a[i].first;
            a[i].second++;
            a[i].first++;
        }
        sort(a + 1, a + 1 + m);
        update(1, 1);
        for(int i = 1; i <= m; ++i) {
            int x = a[i].second, y = a[i].first;
            long long tmp = sum(y - 1) - sum(x - 1);
            tmp = (tmp + MOD) % MOD;
            update(y, tmp);
        }
        long long ans = sum(n + 1) - sum(n);
        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
