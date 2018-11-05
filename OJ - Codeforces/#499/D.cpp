
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N][10];
int val[N];
int l[N], r[N];
set<int> st[N];

void go(int u, int v) {
    if(st[v].size() > st[u].size()) {
        st[u].swap(st[v]);
    }
    for(int x : st[v])
        st[u].insert(x);
    set<int>().swap(st[v]);
}

void dfs(int u) {
    if(*s[u] == 'I') {
        st[u].insert(u);
        return;
    }
    if(*s[u] == 'N') {
        int v = l[u];    
        dfs(v);
        val[u] = !val[v];
        go(u, v);
    }
    else if(*s[u] == 'A') {
        int v1 = l[u], v2 = r[u];
        dfs(v1); dfs(v2);
        val[u] = val[v1] & val[v2];
        if(val[u] != ((val[v1] ^ 1) & val[v2])) {
           go(u, v1); 
        }
        if(val[u] != (val[v1] & (val[v2] ^ 1))) {
           go(u, v2); 
        }
    }
    else if(*s[u] == 'O') {
        int v1 = l[u], v2 = r[u];
        dfs(v1); dfs(v2);
        val[u] = val[v1] | val[v2];
        if(val[u] != ((val[v1] ^ 1) | val[v2])) {
           go(u, v1); 
        }
        if(val[u] != (val[v1] | (val[v2] ^ 1))) {
           go(u, v2); 
        }
    }
    else {
        int v1 = l[u], v2 = r[u];
        dfs(v1); dfs(v2);
        val[u] = val[v1] ^ val[v2];
        if(val[u] != ((val[v1] ^ 1) ^ val[v2])) {
           go(u, v1); 
        }
        if(val[u] != (val[v1] ^ (val[v2] ^ 1))) {
           go(u, v2); 
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", s[i]);
        if(*s[i] == 'I') {
            scanf("%d", val + i);
        }
        else if(*s[i] == 'N') {
            scanf("%d", l + i);
        }
        else {
            scanf("%d%d", l + i, r + i);
        }
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        if(*s[i] == 'I') {
            printf("%d", val[1] ^ (st[1].count(i)));
        }
    }
    puts("");
    return 0;
}
