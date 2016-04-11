//
//  Created by TaoSama on 2015-10-08
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
set<int> s[N];

int par[N], rnk[N];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) {
        par[x] = y;
        for(set<int>::iterator iter = s[x].begin(); iter != s[x].end(); ++iter)
            s[y].insert(*iter);
    } else {
        par[y] = x;
        for(set<int>::iterator iter = s[y].begin(); iter != s[y].end(); ++iter)
            s[x].insert(*iter);
        if(rnk[x] == rnk[y]) ++rnk[x];
    }
}

map<string, int> mp;
int cnt;
inline int ID(string x) {
    if(!mp.count(x)) {
        mp[x] = ++cnt;
        return cnt;
    }
    return mp[x];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) s[i].clear();
        cnt = 0; mp.clear(); init(n);
        for(int i = 1; i <= n; ++i) {
            char op[50]; scanf("%s", op);
            if(*op == 'a') {
                char name[50]; scanf("%s", name);
                int id = ID(name), k;
                scanf("%d", &k);
                while(k--) {
                    int x; scanf("%d", &x);
                    s[id].insert(x);
                }
//              printf("%d have %d\n", id, s[id].size());
            } else if(*op == 's') {
                char name1[50], name2[50];
                scanf("%s%s", name1, name2);
                int x = ID(name1), y = ID(name2);
                unite(x, y);
            } else {
                char name[50]; scanf("%s", name);
                int id = ID(name);
                id = find(id);
                printf("%d\n", s[id].size());
            }
        }
    }
    return 0;
}
