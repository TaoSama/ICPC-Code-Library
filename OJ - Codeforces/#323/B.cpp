//
//  Created by TaoSama on 2015-10-04
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

int n, a[1005];
bool vis[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0, cur = 0;
        int i = 1, dir = 1;
        memset(vis, 0, sizeof vis);
        while(true) {
            if(!vis[i] && cur >= a[i]) {
                ++cur;
                vis[i] = true;
            }
            if(cur == n) break;
            if(i + dir > n || i + dir < 1) {
                ++ans;
                dir = -dir;
            }
            i += dir;
        }
        cout << ans << '\n';
    }
    return 0;
}
