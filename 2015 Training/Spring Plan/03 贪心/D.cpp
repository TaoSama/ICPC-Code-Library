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

int n, m, c[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            cin >> c[i], ans += c[i];

        if(m < n) {
            ans = 0;
            sort(c + 1, c + 1 + n);
            int t = 1, j = 0;
            for(int i = n; i >= 1; --i) {
                ans += t * c[i];
                ++j;
                if(j == m) j = 0, t++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
