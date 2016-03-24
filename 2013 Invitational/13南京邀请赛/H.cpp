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

int n;
bool vis[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(vis, false, sizeof vis);
        int ans;
        for(int i = 1; i <= n + 1; ++i) {
            int x; scanf("%d", &x);
            if(vis[x]) ans = x;
            vis[x] = true;
        }
        printf("%d\n", ans);
    }
    return 0;
}
