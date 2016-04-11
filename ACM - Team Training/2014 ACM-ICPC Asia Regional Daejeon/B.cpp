//
//  Created by TaoSama on 2015-12-16
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
#include <unordered_set>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m1, m2, m3;
int deg[N], vis[N], a[N];
vector<int> type2[N];
unordered_set<int> type3[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m1, &m2, &m3);

        queue<int> q;
        memset(vis, false, sizeof vis);
        while(m1--) {
            int x; scanf("%d", &x);
            if(!vis[x]) q.push(x);
            vis[x] = true;
        }
        for(int i = 1; i <= m2; ++i) {
            type2[i].clear();
            int k; scanf("%d", &k);
            while(k--) {
                int x; scanf("%d", &x);
                type2[i].push_back(x);
            }
        }
        for(int i = 1; i <= m3; ++i) {
            type3[i].clear();
            int k; scanf("%d", &k);
            while(k--) {
                int x; scanf("%d", &x);
                type3[i].insert(x);
            }
            scanf("%d", a + i);
        }

        //find the minimum true values according type3
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 1; i <= m3; ++i) {
                unordered_set<int> &cur = type3[i];
                auto iter = cur.find(u);
                if(iter != cur.end()) {
                    cur.erase(iter);
                    if(!cur.size() && !vis[a[i]]) {
                        vis[a[i]] = true;
                        q.push(a[i]);
                    }
                }
            }
        }

        //test them with type2
        bool result = true;
        for(int i = 1; i <= m2; ++i) {
            int ok = false;
            for(int x : type2[i])
                if(!vis[x]) { ok = true; break; }
            if(!ok) { result = false; break; }
        }
        puts(result ? "YES" : "NO");
    }
    return 0;
}
