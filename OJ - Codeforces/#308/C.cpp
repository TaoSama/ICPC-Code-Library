//
//  Created by TaoSama on 2015-06-19
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long w, m, ct;
bool vis[105];

void dfs(int m, int k) {
    if(m == 0) throw 1;
    while(m % w == 0) {
        m /= w;
        k ++;
        if(k > 100) return;
    }
    if(vis[k]) return;
    vis[k] = 1;
    dfs(m + 1, k);
    dfs(m - 1, k);
    vis[k] = 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> w >> m) {
        memset(vis, false, sizeof vis);
        try {
            dfs(m, 0);
        } catch(int) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
