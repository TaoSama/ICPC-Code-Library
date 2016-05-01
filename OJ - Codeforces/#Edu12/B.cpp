//
//  Created by TaoSama on 2016-04-20
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <list>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k >> m) {
        vector<int> v;
        for(int i = 1; i <= m; ++i) {
            int x; cin >> x;
            v.push_back(x);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                int x; cin >> x;
                auto iter = find(v.begin(), v.end(), x);
                ans += iter - v.begin() + 1;
                v.erase(iter);
                v.insert(v.begin(), x);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
