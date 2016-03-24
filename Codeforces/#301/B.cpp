//
//  Created by TaoSama on 2015-05-08
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

int n, k, p, x, y;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k >> p >> x >> y) {
        int sum = 0, cnt = 0;
        for(int i = 1; i <= k; ++i) {
            int x; cin >> x;
            sum += x;
            if(x >= y) ++cnt;
        }
        if(sum + n - k > x) {
            cout << "-1\n";
            continue;
        }

        int r = max(0, (n + 1) / 2 - cnt);
        int l = n - k - r;
        if(sum + l + r * y > x || k + r > n) cout << "-1\n";
        else {
            for(int i = 1; i <= l; ++i)
                cout << 1 << ' ';
            for(int i = 1; i <= r; ++i)
                cout << y << ' ';
            cout << '\n';
        }

    }
    return 0;
}
