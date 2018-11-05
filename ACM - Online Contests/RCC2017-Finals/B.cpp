
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int P[2] = {MOD, MOD + 2};

int n;
char buf[N];
string s[N];
typedef unsigned long long ULL;
vector<int> prefix[2][N];
vector<int> G[N];
int power[2][N];

const int SEED = 233;

inline pair<int, int> getHash(int i, int l, int r) {
    int h[2];
    for(int k = 0; k < 2; ++k) {
        h[k] = prefix[k][i][r] - 1LL * (l ? prefix[k][i][l - 1] : 0) * power[k][r - l + 1] % P[k] + P[k];
        if(h[k] >= P[k]) h[k] -= P[k];
    }
    return {h[0], h[1]};
}

bool vis[N];
int f[N][2];

void dfs(int u) {
    f[u][0] = 0, f[u][1] = 1;
    vis[u] = true;
    for(int v : G[u]) {
        if(vis[v]) continue;
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    for(int k = 0; k < 2; ++k) {
        power[k][0] = 1;
        for(int i = 1; i < N; ++i) power[k][i] = 1LL * power[k][i - 1] * SEED % P[k]; 
    }
    
    int t; scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            prefix[0][i].clear();
            prefix[1][i].clear();
        }

        map<pair<int, int>, int> hashes;
        int vs = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", buf);
            s[i] = buf;
            int h1 = 0, h2 = 0;
            for(int j = 0; buf[j]; ++j) {
                h1 = (1LL * h1 * SEED + buf[j]) % P[0];
                h2 = (1LL * h2 * SEED + buf[j]) % P[1];
                prefix[0][i].push_back(h1);
                prefix[1][i].push_back(h2);
                // printf("h1 = %d h2 = %d\n", h1, h2);
                if(hashes.count({h1, h2})) continue;
                hashes[{h1, h2}] = ++vs;
            }
        }

        // printf("Pre succeed!\n");
        
        for(int i = 1; i <= vs; ++i) G[i].clear(), vis[i] = 0;
        // puts("here");
        for(int i = 1; i <= n; ++i) {
            for(size_t j = 1; j < s[i].size(); ++j) {
                auto p = getHash(i, 1, j), h = getHash(i, 0, j);
                int u = hashes[h];
                if(hashes.count(p)) {
                    int fa = hashes[p];
                    // printf("%d %d\n", fa, u);
                    G[fa].push_back(u);
                    G[u].push_back(fa);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= vs; ++i) {
            if(vis[i]) continue;
            dfs(i);
            // printf("%d = %d %d\n", i, f[i][0], f[i][1]);
            ans += max(f[i][0], f[i][1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
