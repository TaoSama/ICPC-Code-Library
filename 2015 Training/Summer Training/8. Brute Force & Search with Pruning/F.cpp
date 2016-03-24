//
//  Created by TaoSama on 2015-07-26
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

int ans, cnt, G[26][26];
bool have[26];
vector<int> V, path;

void add_edge(string& s) {
    int u, v;
    bool lef = true;
    for(int i = 0; i < s.size(); ++i) {
        if(isalpha(s[i])) {
            if(lef) {
                u = s[i] - 'A';
                if(!have[u]) have[u] = true, V.push_back(u);
            } else {
                v = s[i] - 'A';
//                cout << u << ' ' << v << endl;
                if(!have[v]) have[v] = true, V.push_back(v);
                G[u][v] = G[v][u] = true;
            }
        } else if(s[i] == ':') lef = false;
        else lef = true;
    }
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(cin >> s && s != "#") {
        memset(have, false, sizeof have);
        memset(G, 0, sizeof G);
        V.clear();
        add_edge(s);
//      for(int i = 0; i < 26; ++i) if(have[i]) ++cnt;

//      prln(cnt);
//      for(int i = 0; i < 26; ++i)
//          for(int j = i + 1; j < 26; ++j)
//              if(G[i][j]) cout << i << ' ' << j << endl;

//      cout << V.size() << endl;
        sort(V.begin(), V.end());
        int ans = INF;
        do {
            int dis = 1;
            bool can = true;
            for(int i = 0; i < V.size(); ++i) {
                for(int j = i + 1; j < V.size(); ++j) {
                    if(G[V[i]][V[j]]) {
                        dis = max(dis, j - i);
                        if(dis >= ans) {
                            can = false;
                            break;
                        }
                    }
                }
                if(!can) break;
            }
            if(can) {
                ans = dis;
                path = V;
            }
        } while(next_permutation(V.begin(), V.end()));

        for(int i = 0; i < path.size(); ++i)
            cout << char(path[i] + 'A') << ' ';
        cout << "-> " << ans << '\n';
    }
    return 0;
}
