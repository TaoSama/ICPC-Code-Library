//
//  Created by TaoSama on 2015-05-23
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

int n, a[35][35];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin >> a[i][j];
        int ans = n * 2;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                if(a[i][j]) ans += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
