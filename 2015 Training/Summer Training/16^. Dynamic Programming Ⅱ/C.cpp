//
//  Created by TaoSama on 2015-08-07
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

int n;
string u, v;
vector<int> G[205];
int d[205][2], f[205][2];
//d[u][0,1]:= maximum people of choosing u or not
//f[u][0,1]:= and corresponding uniqueness

int cnt;
map<string, int> mp;

int ID(string& s) {
    if(!mp.count(s)) mp[s] = ++cnt;
    return mp[s];
}

int dfs(int u, int k) {
    d[u][k] = k; //choose or not
    f[u][k] = 1;
    for(auto &v : G[u]) {
        if(k) {
            d[u][1] += dfs(v, 0);
            if(!f[v][0]) f[u][1] = 0;
        } else {
            d[u][0] += max(dfs(v, 1), dfs(v, 0));
            if(d[v][1] == d[v][0]) f[u][0] = 0; // equal not unique
            //son not unique
            else if(d[v][1] > d[v][0] && !f[v][1]) f[u][0] = 0;
            else if(d[v][0] > d[v][1] && !f[v][0]) f[u][0] = 0;
        }
    }
    return d[u][k];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        cnt = 0; mp.clear();
        cin >> u; ID(u);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            cin >> v >> u;
            G[ID(u)].push_back(ID(v));
        }
        printf("%d ", max(dfs(1, 0), dfs(1, 1)));
        bool one = false;
        if(d[1][0] > d[1][1] && f[1][0]) one = true;
        if(d[1][1] > d[1][0] && f[1][1]) one = true;
        puts(one ? "Yes" : "No");
    }
    return 0;
}
