//
//  Created by TaoSama on 2015-07-30
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

int n, maxd, sum, a[105];
bool vis[105];

bool dfs(int cur, int from, int cnt) {
    if(cnt * maxd == sum) return true;
    for(int i = from; i <= n; ++i) {
        if(vis[i]) continue;
        if(cur + a[i] == maxd) {
            vis[i] = true;
            if(dfs(0, 1, cnt + 1)) return true;
            vis[i] = false;
            return false;  //the following can't just backtrack to previous
        } else if(cur + a[i] < maxd) {
            vis[i] = true;
            if(dfs(cur + a[i], i + 1, cnt)) return true;
            vis[i] = false;
            if(cur == 0) return false; //so small
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        sum = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + 1 + n, greater<int>());

        bool ok = false;
        for(maxd = a[1]; maxd + maxd <= sum; ++maxd) {
            if(sum % maxd == 0) {
                memset(vis, false, sizeof vis);
                if(dfs(0, 1, 0)) {
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) maxd = sum;
        cout << maxd << '\n';
    }
    return 0;
}
