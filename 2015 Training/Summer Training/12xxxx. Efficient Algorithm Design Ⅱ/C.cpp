//
//  Created by TaoSama on 2015-08-01
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

int n, a[N], pre[N], nxt[N];
map<int, int> mp;

bool dfs(int l, int r) {
    if(l >= r) return true;
    for(int i = 0; i <= (r - l + 1) / 2; ++i) {
        if(pre[l + i] < l && nxt[l + i] > r)
            return dfs(l, l + i - 1) && dfs(l + i + 1, r);
        if(pre[r - i] < l && nxt[r - i] > r)
            return dfs(l, r - i - 1) && dfs(r - i + 1, r);
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = -1;
            nxt[i] = n + 1;
        }
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            if(mp.count(a[i])) {
                pre[i] = mp[a[i]];
                nxt[pre[i]] = i;
            }
            mp[a[i]] = i;
        }

        if(dfs(1, n)) cout << "non-boring\n";
        else cout << "boring\n";
    }
    return 0;
}
