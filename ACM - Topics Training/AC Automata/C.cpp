//
//  Created by TaoSama on 2015-11-27
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1000 * 50 + 10, S = 128;

int n, cnt[1005];
char virus[1005][55], s[N];

struct AcAutomata {
    int root, sz;
    int nxt[M][S], fail[M], id[M];
    int newNode() {
        id[sz] = -1;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(char *s, int x) {
        int n = strlen(s);
        int u = root;
        for(int i = 0; i < n; ++i) {
            int &v = nxt[u][s[i]];
            if(v == -1) v = newNode();
            u = v;
        }
        id[u] = x;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int &v = nxt[root][i];
            if(~v) {
                fail[v] = root;
                q.push(v);
            } else v = root;
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < S; ++i) {
                int &v = nxt[u][i];
                if(~v) {
                    fail[v] = nxt[fail[u]][i];
                    q.push(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    void query(char *s) {
        memset(cnt, 0, sizeof cnt);
        int u = root;
        for(int i = 0; s[i]; ++i) {
            u = nxt[u][s[i]];
            for(int v = u; v != root; v = fail[v])
                if(~id[v]) ++cnt[id[v]];
        }
        for(int i = 1; i <= n; ++i)
            if(cnt[i]) printf("%s: %d\n", virus[i], cnt[i]);
    }
} ac;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        ac.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", virus[i]);
            ac.insert(virus[i], i);
        }
        ac.build();
        scanf("%s", s);
        ac.query(s);
    }
    return 0;
}
