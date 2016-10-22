//
//  Created by TaoSama on 2015-10-31
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 5e5 + 10;
const int S = 26;

int n;
char s[N];

struct AcAutomata {
    int root, sz;
    int nxt[M][S], fail[M], cnt[M];
    int newNode() {
        cnt[sz] = 0;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void insert(char* s) {
        int n = strlen(s);
        int u = root;
        for(int i = 0; i < n; ++i) {
            int& v = nxt[u][s[i] - 'a'];
            if(v == -1) v = newNode();
            u = v;
        }
        ++cnt[u];
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
            if(~v) {
                fail[v] = root;
                q.push(v);
            } else v = root;
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(~v) {
                    fail[v] = nxt[fail[u]][i];
                    q.push(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    int query(char* s) {
        int n = strlen(s);
        int u = root, ret = 0;
        for(int i = 0; i < n; ++i) {
            u = nxt[u][s[i] - 'a'];
            for(int v = u; v != root; v = fail[v]) {
                ret += cnt[v];
                cnt[v] = 0;
            }
        }
        return ret;
    }
    void debug() {
        for(int i = 0; i < sz; ++i) {
            printf("id = %3d, fail = %3d, cnt = %3d, chi = [",
                   i, fail[i], cnt[i]);
            for(int j = 0; j < S; j++)
                printf("%2d", nxt[i][j]);
            printf("]\n");
        }
    }
} ac;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        ac.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        scanf("%s", s);
        printf("%d\n", ac.query(s));
    }
    return 0;
}
