//
//  ACdream 1865 娜娜梦游仙境系列——多民族王国
//
//  Created by TaoSama on 2015-04-11
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

int n, m;
vector<int> Lan[105];
struct Edge {
    int u, v;
};
vector<Edge> G;

int par[105], rank[105];
bool learned;

int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void solve() {
    for(int i = 1; i <= n; ++i) par[i] = i, rank[i] = 0;
    for(int i = 0; i < G.size(); ++i){
		Edge e = G[i];
		e.u = find(e.u); e.v = find(e.v);
		if(e.u != e.v) {
			if(rank[e.u] < rank[e.v]) par[e.u] = e.v;
			else{
				par[e.v] = e.u;
				if(rank[e.u] == rank[e.v]) ++rank[e.u];
			}
		}
    }
    set<int> s;
    for(int i = 1; i <= n; ++i) {
		s.insert(par[i]);
    }
    int ans = s.size();
    if(learned) --ans;
    printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        learned = false;
        G.clear();
        for(int i = 1; i <= m; ++i) Lan[i].clear();
        for(int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            while(k-- > 0) {
				learned = true;
                int x; scanf("%d", &x);
                Lan[x].push_back(i);
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 0; j < Lan[i].size(); ++j) {
                int &u = Lan[i][j];
                for(int k = 0; k < Lan[i].size(); ++k) {
                    int &v = Lan[i][k];
                    if(u == v) continue;
                    G.push_back((Edge) {u, v});
                }
            }
        }
		/*for(int i = 0; i < G.size(); ++i){
			cout<<G[i].u <<' '<<G[i].v<<endl;
		}*/
		solve();
    }
    return 0;
}
