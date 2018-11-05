
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int l[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 1; i <= m; ++i) scanf("%d", l + i);
        int ok = true;
        vector<int> used(n + 1, 0), ans(n + 1, 0);
        for(int i = 1; i < m; ++i){
            int a = (l[i + 1] - l[i] + n) % n;
            if(!a) a = n;
            if(used[a] && used[a] != l[i]) ok = false;
            used[a] = l[i];
            ans[l[i]] = a;
        }
//        for(int i = 1; i <= n; ++i) printf("%2d%c", ans[i], " \n"[i == n]);
        for(int i = 1, j = 1; i <= n; ++i){
            if(!ans[i]){
                for(; j <= n && used[j]; ++j);
                if(j > n) ok = false;
                ans[i] = j++;
            }
        }
        if(!ok) puts("-1");
        else{
            for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}
