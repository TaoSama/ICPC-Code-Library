//
//  Created by TaoSama on 2015-05-11
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
const int N = 1e5 + 10;

long long a, b;

long long calc(long long x) {
    bool more = false;
    for(long long i = x / 10 * 10; i <= x; ++i) {
        long long t = i, sum = 0;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        if(sum % 10 == 0) {
            more = true;
            break;
        }
    }
    return x / 10 + more;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    while(t--) {
        cin >> a >> b;
        long long ans = calc(b) - calc(a - 1);
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
    return 0;
}
