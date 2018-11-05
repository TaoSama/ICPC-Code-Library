
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int m, n, p[N];

int main(){
#ifdef LOCAL
    // freopen("/Users/didi/ACM/in.txt", "r", stdin);
    //  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 1; i <= n; ++i) {
        cout << 1 << endl;
        int x; cin >> x;
        if(x == 0) {
            return 0;
        }
        else {
            p[i] = x == 1 ? 1 : 0;
        }
    }

    int l = 1, r = m;
    for(int i = 1; i <= 30; ++i) {
        int j = (i - 1) % n + 1;
        int z = (l + r) / 2;
        cout << z << endl;
        int x; cin >> x;
        if(!p[j]) {
            x = -x;
        }
        if(x == 0) {
            return 0;
        }
        else if(x == 1) {
            l = z + 1;
        }
        else {
            r = z - 1;
        }
    }
    return 0;
}
