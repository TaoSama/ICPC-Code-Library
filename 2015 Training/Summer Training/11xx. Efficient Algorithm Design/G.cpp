//
//  Created by TaoSama on 2015-07-31
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        set<int> s;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0, l = 1, r = 1;
        while(r <= n) {
            while(r <= n && !s.count(a[r])) s.insert(a[r++]);
            ans = max(ans, r - l);
            s.erase(a[l++]);
        }
        cout << ans << '\n';
    }
    return 0;
}
