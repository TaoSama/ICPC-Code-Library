//
//  Created by TaoSama on 2015-07-27
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

int n, a[105], mp[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(mp, 0, sizeof mp);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }

        int ans = 0;
        for(int i = 0; i <= 100; ++i) {
            for(int j = 0; j <= 100; ++j) {
                if(i == j) {
                    ans += mp[i] / 4;
                    mp[i] -= mp[i] / 4 * 4;
                    continue;
                }
                int x = mp[i] / 2, y = mp[j] / 2;
                int t = min(x, y);
                ans += t;
                mp[i] -= t * 2; mp[j] -= t * 2;
                if(mp[i] <= 1) break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
