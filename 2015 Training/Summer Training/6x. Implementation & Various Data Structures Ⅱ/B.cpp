//
//  Created by TaoSama on 2015-07-24
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, in[26], out[26];
vector<int> G[26];
bool vis[26];

void dfs(int u) {
    vis[u] = false;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
//        cout << u << ' ' << v << endl;
        if(!vis[v]) continue;
        dfs(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < 26; ++i) G[i].clear();
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s;
            int u = s[0] - 'a', v = s[s.size() - 1] - 'a';
            vis[u] = vis[v] = true;
            out[u]++, in[v]++;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int cnt = 0;
        for(int i = 0; i < 26; ++i) {
            if(vis[i]) ++cnt, dfs(i);
        }
//        prln(cnt);
        bool euler = false;
        if(cnt == 1) {
            vector<int> no;
            for(int i = 0; i < 26; ++i) {
                if(in[i] != out[i]) {
                    no.push_back(i);
                }
            }
            if(no.size() == 2) {
                if(in[no[0]] - out[no[0]] == 1 && out[no[1]] - in[no[1]] == 1)
                    euler = true;
                if(out[no[0]] - in[no[0]] == 1 && in[no[1]] - out[no[1]] == 1)
                    euler = true;
            }
            else if(no.size() < 2) euler = true;
        }
        if(!euler) cout << "The door cannot be opened.\n";
        else cout << "Ordering is possible.\n";
    }
    return 0;
}
