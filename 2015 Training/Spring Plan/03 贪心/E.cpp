//
//
//
//  Created by TaoSama on 2015-04-22
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

int n, k, a[1005], b[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n, greater<int>());
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(a[i] + b[i] < k) {
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
