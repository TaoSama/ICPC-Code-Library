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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[60];
vector<int> G[60];

int get(char x1, char x2) {
    return 2 * (x1 - 'A') + (x2 == '+');
}

//add one-way edge with rev vertex
//to simulate the two vertex are bidirectional without cycle.
//A+ <-> B-   =>  A- -> B- & B+ -> A+
//once got and edge with A- & B+ that forms a cycle, but the original's not
void add_edge(char* s) {
    for(int i = 1; i <= 8; i += 2) {
        for(int j = 1; j <= 8; j += 2) {
            if(s[i] == '0' || s[j] == '0' || i == j) continue;
            int u = get(s[i], s[i + 1]) ^ 1, v = get(s[j], s[j + 1]);
            G[u].push_back(v);
        }
    }
}

bool dfs(int u) {
    c[u] = -1;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(c[v] < 0) return false;
        if(!c[v] && !dfs(v)) return false;
    }
    c[u] = 1;
    return true;
}

bool topo() {
    memset(c, 0, sizeof c);
    for(int i = 0; i < 52; ++i) {
        if(!c[i] && !dfs(i)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 0; i < 52; ++i) G[i].clear();

        for(int i = 1; i <= n; ++i) {
            char s[10]; cin >> (s + 1);
            add_edge(s);
        }

        if(topo()) cout << "bounded\n";
        else cout << "unbounded\n";
    }
    return 0;
}
