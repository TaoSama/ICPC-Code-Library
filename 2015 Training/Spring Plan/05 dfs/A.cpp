//
//  Created by TaoSama on 2015-05-29
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

int n, ans, l[15], r[15];
bool vis[15];

void dfs(int dep, int last, int first) {

    if(dep == n + 1) {
        if(__gcd(l[first], r[last]) == 1) {
            /*for(int i = 0; i < n; ++i) {
                char c = cur[0]; cur.erase(0, 1); cur += c;
                if(s.count(cur)) return;
            }*/
            //s.insert(cur);
            ++ans;
        }
        return;
    }

    for(int i = 2; i <= n; ++i) {
        if(!vis[i]) {
            if(__gcd(l[i], r[last]) == 1) {
                vis[i] = true;
                dfs(dep + 1, i, first);
                vis[i] = false;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        //s.clear();
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", l + i, r + i);

        ans = 0;
        if(n != 1) dfs(2, 1, 1);
        else ans = 0;

        printf("%d\n", ans);
        /*for(auto i : s) {
            cout << i << endl;
        }*/
    }
    return 0;
}
