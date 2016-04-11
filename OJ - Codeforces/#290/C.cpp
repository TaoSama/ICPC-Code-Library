//
//  Created by TaoSama on 2015-05-18
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

string a[105], ans;
int n, c[26];
vector<int> G[26];

bool dfs(int u) {
    c[u] = -1;
    for(int i = 0; i < G[u].size(); ++i) {
        int &v = G[u][i];
        if(c[v] < 0 || !c[v] && !dfs(v)) return false;
    }
    c[u] = 1; ans = (char)(u + 'a') + ans;
    return true;
}

bool toposort() {
    ans.clear();
    memset(c, 0, sizeof c);
    for(int i = 0; i < 26; ++i)
        if(!c[i] && !dfs(i)) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
		for(int i = 0; i < 26; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) cin >> a[i];
        bool ok = true;
        for(int i = 1; i < n; ++i) {
            bool prefix = true;
            for(int j = 0; j < min(a[i].size(), a[i + 1].size()); ++j) {
                if(a[i][j] != a[i + 1][j]) {
                    prefix = false;
                    G[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
                    break;
                }
            }
            if(prefix && a[i].size() > a[i + 1].size()) {
                ok = false;
                break;
            }
        }
        if(!ok || !toposort()) cout << "Impossible\n";
        else cout << ans << '\n';
    }
    return 0;
}
