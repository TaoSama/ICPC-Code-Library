//
//  Created by TaoSama on 2015-05-10
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

int n, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        int sum = 0, x;
        for(int i = 1; i <= n; ++i) {
            cin >> x;
            sum += x;
        }
        cin >> m;
        for(int i = 1; i <= m; ++i) cin >> x;
        if(sum == 0) cout << 0.00 << '\n';
        else if(n == m) cout << "inf\n";
        else cout << fixed << setprecision(2) << 1.0 * sum / (n - m) << '\n';
    }
    return 0;
}
