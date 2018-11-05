
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[N];
vector<int> g[N];

const double EPS = 1e-8;
int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}
bool combine(double &l1, double &r1, double l2, double r2)
{
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	return l1 <= r1;
}
int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            char buf[100]; cin >> buf;
            if(*buf == '*') a[i] = INF;
            else a[i] = atoi(buf);
            g[i].clear();
        }
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        double l = -1e7, r = 1e7;
        for(int i = 1; i <= 100; ++i) {
            auto can = [&](double x) {
                vector<pair<double, double>> bound(n + 1); 
                for(int u = 1; u <= n; ++u) {
                    if(a[u] == INF) bound[u] = {-1e7, 1e7};
                    else bound[u] = {a[u], a[u]};
                }
                for(int u = 1; u <= n; ++u) {
                    for(int v : g[u]) {
                        if(a[v] != INF && a[u] != INF) {
                            if(sgn(abs(a[u] - a[v]) - x) > 0) return false;
                        }
                        else if(a[v] != INF) {
                            
                        }
                    }
                }
            };
            double m = (l + r) / 2;
            if(can(m)) r = m;
            else l = m;
        }
    }
    return 0;
}
