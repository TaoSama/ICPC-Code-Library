//
//  Created by TaoSama on 2017-04-23
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    for(int i = 0; i < n; ++i) c[i] = i;
    sort(c.begin(), c.end(), [&](int x, int y) {
        return b[x] > b[y];
    });

    vector<int> ans; ans.push_back(c[0]);
    for(int i = 1; i + 1 < n; i += 2) {
        if(a[c[i]] >= a[c[i + 1]]) ans.push_back(c[i]);
        else ans.push_back(c[i + 1]);
    }
    if(~n & 1) ans.push_back(c[n - 1]);

    cout << ans.size() << endl;
    for(int x : ans) cout << x + 1 << ' '; cout << endl;

    return 0;
}
