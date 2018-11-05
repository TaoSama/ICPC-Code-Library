
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, p;
int a[N], b[N];

vector<int> G[N];
int vis[N], match[N];
int dfs(int u){
    for(int v : G[u]){
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool check(long long m){
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            long long dis = abs(a[i] - b[j]) + abs(b[j] - p);
            if(dis <= m) G[i].push_back(j);
        }
    }
    vector<int> matched(n + 1);
    for(int j = 1; j <= k; ++j){
        int i = match[j];
        if(i == -1) continue;
        long long dis = abs(a[i] - b[j]) + abs(b[j] - p);
        if(dis <= m) matched[i] = true;
        else match[j] = -1;
    }
    for(int i = 1; i <= n; ++i){
        if(matched[i]) continue;
        for(int j = 1; j <= k; ++j) vis[j] = false;
        if(!dfs(i)) return false;
    }
    return true;
}


int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> k >> p){
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= k; ++i) cin >> b[i];
       
        for(int i = 1; i <= k; ++i) match[i] = -1;
        long long l = 0, r = 1e10, ans = -1;
        while(l <= r){
            long long m = (l + r) / 2;
            if(check(m)) ans = m, r = m - 1;
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
