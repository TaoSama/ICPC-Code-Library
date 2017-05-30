//
//  Created by TaoSama on 2017-05-04
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        long long ans = 0, b = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'a') {
                ans = (ans + b) % MOD;
                b = b * 2 % MOD;
            } else ++b;
        }
        cout << ans << endl;
    }

    return 0;
}
