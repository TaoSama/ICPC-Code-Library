//
//  Created by TaoSama on 2017-04-13
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
    auto isPrime = [](int x) {
        for(int i = 2; i * i <= x; ++i)
            if(x % i == 0) return false;
        return x != 1;
    };
    int cnt = 0;
    for(int i = n - 1; cnt < 10; --i) {
        if(!isPrime(i)) continue;
        ++cnt;
        cout << setw(6) << i;
    }
    cout << endl;

    return 0;
}
