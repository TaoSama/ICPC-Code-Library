//
//  Created by TaoSama on 2015-08-06
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, dp[100];
struct Cube {
    int l, w, h;
    bool operator<(const Cube& rhs) const {
        return l * w > rhs.l * rhs.w;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        vector<Cube> v;
        for(int i = 1; i <= n; ++i) {
            int x, y, z; cin >> x >> y >> z;
            v.push_back((Cube) {x, y, z});
            v.push_back((Cube) {y, z, x});
            v.push_back((Cube) {x, z, y});
        }
        sort(v.begin(), v.end());

        memset(dp, 0, sizeof dp);
        //dp[i]:= i-th cube as the top cube's maximum height
        int ans = -INF;
        for(int i = 0; i < v.size(); ++i) {
            dp[i] = v[i].h;
            for(int j = 0; j < i; ++j) {
                if(v[j].l > v[i].l && v[j].w > v[i].w ||
                        v[j].w > v[i].l && v[j].l > v[i].w)
                    dp[i] = max(dp[i], dp[j] + v[i].h);
            }
            ans = max(ans, dp[i]);
        }
        cout << "Case " << ++kase << ": maximum height = ";
        cout << ans << '\n';
    }
    return 0;
}
