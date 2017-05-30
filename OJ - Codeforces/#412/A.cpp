//
//  Created by TaoSama on 2017-05-07
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        bool same = 1;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
            same &= a[i] == b[i];
        }
        bool dec = 1;
        for(int i = 1; i < n; ++i) dec &= a[i] >= a[i + 1];

        if(same) {
            if(dec) cout << "maybe\n";
            else cout << "unrated\n";
        } else cout << "rated\n";
    }

    return 0;
}
