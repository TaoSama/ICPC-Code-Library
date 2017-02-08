//
//  Created by TaoSama on 2017-02-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n, m, q;

int cnt;
map<string, int> mp;
int ID(string& s) {
    if(!mp.count(s)) mp[s] = ++cnt;
    return mp[s];
}

struct DSU {
    int n, p[2 * N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= 2 * n; ++i) p[i] = i;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        p[x] = y;
    }
} dsu;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> q) {
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s;
            ID(s);
        }
        dsu.init(n);

        while(m--) {
            int op; string a, b; cin >> op >> a >> b;
            int ida = ID(a), idb = ID(b);
//            cout << ida << ' ' << idb << endl;
            if(op == 1) {
                if(!dsu.same(ida, idb + n) && !dsu.same(ida + n, idb)) {
                    dsu.unite(ida, idb);
                    dsu.unite(ida + n, idb + n);
                    cout << "YES\n";
                } else cout << "NO\n";
            } else {
                if(!dsu.same(ida, idb) && !dsu.same(ida + n, idb + n)) {
                    dsu.unite(ida, idb + n);
                    dsu.unite(ida + n, idb);
                    cout << "YES\n";
                } else cout << "NO\n";
            }
        }
        while(q--) {
            string a, b; cin >> a >> b;
            int ida = ID(a), idb = ID(b);
            if(dsu.same(ida, idb)) cout << 1 << '\n';
            else if(dsu.same(ida, idb + n)) cout << 2 << '\n';
            else cout << 3 << '\n';
        }
    }

    return 0;
}
