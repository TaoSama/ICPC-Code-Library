//
//  Created by TaoSama on 2017-06-11
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

    int n; scanf("%d", &n);
    vector<int> a(n);
    for(auto& x : a) scanf("%d", &x);

    int m; scanf("%d", &m);
    vector<int> b(m);
    for(auto& x : b) scanf("%d", &x);

    int ans = 2e9;
    for(int i = 0; i + n - 1 < m; ++i) {
        int tmp = 0;
        for(int j = 0; j < n; ++j)
            tmp += (a[j] - b[i + j]) * (a[j] - b[i + j]);
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);

    return 0;
}
