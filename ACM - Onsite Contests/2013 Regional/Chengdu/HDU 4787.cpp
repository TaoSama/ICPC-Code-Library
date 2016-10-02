//
//  Created by TaoSama on 2016-08-23
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct ACAutomata {
    static const int S = 2;
    int sz, root;
    vector<vector<int> > nxt;
    vector<int> fail, cnt;

    inline int idx(char c) {return c - '0';}
    inline int newNode() {
        cnt.push_back(0);
        nxt.push_back(vector<int>(S, 0));
        return sz++;
    }
    void init() {
        sz = 0;
        nxt.clear();
        cnt.clear();
        fail.clear();
        root = newNode();
    }
    void insert(const char* s, int d) {
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            int& v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
        }
        cnt[u] += d;
    }
    void build() {
        vector<int> q;
        fail.resize(nxt.size());
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
            if(v) {
                fail[v] = root;
                q.push_back(v);
            } else v = root;
        }
        for(int k = 0; k < q.size(); ++k) {
            int u = q[k];
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(v) {
                    fail[v] = nxt[fail[u]][i];
                    cnt[v] += cnt[nxt[fail[u]][i]];
                    q.push_back(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    LL query(const char* s) {
        LL ret = 0;
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            u = nxt[u][c];
            ret += cnt[u];
        }
        return ret;
    }
};

int q, op[N];
string s[N];

struct StaticToDynamic {
    static const int LOG = 20;
    ACAutomata ac[LOG];
    vector<int> g[LOG];

    void init() {
        for(int i = 0; i < LOG; ++i) {
            g[i].clear();
            ac[i].init();
        }
    }
    inline get(int x) {
        return x == 1 ? 1 : -1;
    }
    void add(int id) {
        int p = -1;
        for(int i = 0; i < LOG && !~p; ++i) if(g[i].empty()) p = i;
        g[p].push_back(id);
        ac[p].insert(s[id].c_str(), 1);

        for(int i = 0; i < p; ++i) {
            for(int id : g[i]) {
                g[p].push_back(id);
                ac[p].insert(s[id].c_str(), 1);
            }
            g[i].clear();
            ac[i].init();
        }
        ac[p].build();
    }
    LL query(int id) {
        LL ret = 0;
        for(int i = 0; i < LOG; ++i) ret += ac[i].query(s[id].c_str());
        return ret;
    }
} solver;

string o;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        static int kase = 0;
        cout << "Case #" << ++kase << ":\n";

        solver.init();
        cin >> q;
        LL last = 0;
        set<string> vis;
        for(int i = 1; i <= q; ++i) {
            cin >> o;
            int shift = last % (o.size() - 1);
            s[i] = string(o.begin() + shift + 1, o.end());
            s[i] += string(o.begin() + 1, o.begin() + shift + 1);

            if(o[0] == '+') {
                if(vis.count(s[i])) continue;
                vis.insert(s[i]);
                solver.add(i);
            } else {
                last = solver.query(i);
                cout << last << '\n';
            }
        }
    }

    return 0;
}
