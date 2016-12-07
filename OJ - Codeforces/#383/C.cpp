//
//  Created by TaoSama on 2016-12-06
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

int n, a[N];

int check(int x, int t) {
    while(t--) x = a[x];
    return x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        vector<int> in(n + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> a[i], ++in[a[i]];
        bool ok = true;
        for(int i = 1; i <= n && ok; ++i) ok &= in[i];
        if(!ok) {puts("-1"); continue;}

        int ans = 1;
        vector<bool> vis(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            int u = i, cycle = 0;
            do {
                vis[u] = true;
                ++cycle;
                u = a[u];
            } while(u != i);
            if(cycle % 2 == 0) cycle /= 2;
            ans = ans / __gcd(ans, cycle) * cycle;
        }

        cout << ans << endl;
    }

    return 0;
}
