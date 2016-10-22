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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 500 * 200 + 10, S = 128;

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
    bool query(char *s, int x) {
        int n = strlen(s);
        int u = root, ok = false;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            u = nxt[u][s[i]];
            for(int v = u; v != root; v = fail[v]) {
                if(~id[v]) {
                    ok = true;
                    ans.push_back(id[v]);
                }
            }
        }
        if(!ok) return false;
        printf("web %d: ", x);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        return true;
    }
} ac;

int n, q;
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        ac.init();
        for(int i = 1; i <= n; ++i) {
            char buf[205]; scanf("%s", buf);
            ac.insert(buf, i);
        }
        ac.build();
        scanf("%d", &q);
        int ans = 0;
        for(int i = 1; i <= q; ++i) {
            scanf("%s", s);
            ans += ac.query(s, i);
        }
        printf("total: %d\n", ans);
    }
    return 0;
}
