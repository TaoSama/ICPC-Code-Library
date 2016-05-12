//
//  Created by TaoSama on 2016-02-27
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int M = 1e6 + 10, S = 26;

int n, m;
string s, t[N];
int f[N];

struct AcAutomata {
    int root, sz;
    int nxt[M][S], id[M];
    int newNode() {
        id[sz] = -1;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(string & s, int x) {
        int u = root;
        for(int i = s.size() - 1; ~i; --i) {
            int c = tolower(s[i]) - 'a';
            int &v = nxt[u][c];
            if(v == -1) v = newNode();
            u = v;
        }
        id[u] = x;
    }

    void query(int idx) {
        int u = root;
        for(int i = idx; i < s.size(); ++i) {
            u = nxt[u][s[i] - 'a'];
            if(u == -1) return;
            if(~id[u] && !f[i + 1])
                f[i + 1] = id[u];
        }
    }
} ac;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> s >> m;
    ac.init();
    for(int i = 1; i <= m; ++i) {
        cin >> t[i];
        ac.insert(t[i], i);
    }
    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        if(!f[i]) continue;
        ac.query(i);
    }
    vector<int> ans;
    int u = n;
    while(u) {
        ans.push_back(f[u]);
        u -= t[f[u]].size();
    }
    for(int i = ans.size() - 1; ~i; --i)
        cout << t[ans[i]] << (" \n"[!i]);
    return 0;
}
