//
//
//
//  Created by TaoSama on 2015-04-22
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n, par[N], ans[N];
bool vis[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 2; i <= n; ++i) cin >> par[i];

    int cnt = 0;
    memset(vis, false, sizeof vis);
    for(int i = n; i > 1; --i) {
        if(!vis[i] && !vis[par[i]]) {
            ans[++cnt] = i;
            vis[par[i]] = true;
        }
    }
    cout << cnt << "000\n";
    for(int i = cnt; i >= 1; --i) {
        if(i != 1) cout << ans[i] << ' ';
        else cout << ans[i] << '\n';
    }
    return 0;
}
