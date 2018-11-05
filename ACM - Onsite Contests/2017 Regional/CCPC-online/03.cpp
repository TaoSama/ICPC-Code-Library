
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int g[10][10];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j){
                if(n > 8) {
                    int x; scanf("%d", &x);
                }
                else {
                    scanf("%d", g[i] + j);
                    g[j][i] = g[i][j];
                }    
            }
        }
        if(n > 8) puts("Bad Team!");
        else{
            int ok = true;
            for(int i = 1; i <= n; ++i) {
                for(int j = i + 1; j <= n; ++j){
                    for(int k = j + 1; k <= n; ++k) {
                        if(g[i][j] && g[j][k] && g[i][k]) ok = false;
                        if(!g[i][j] && !g[j][k] && !g[i][k]) ok = false;
                    }
                }
            }
            puts(!ok && n >= 3 ? "Bad Team!" : "Great Team!");
        }
    }
    return 0;
}
