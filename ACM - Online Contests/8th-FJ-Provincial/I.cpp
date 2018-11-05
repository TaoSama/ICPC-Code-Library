
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int w[N];
typedef unsigned long long ULL;
char s[N];
ULL hashVal[N];
ULL suffixHash[N][N];
bool isSuffix[N][N];
const int P = 2000003;
int timStp, vis[P];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%s%d", s + 1, w + i);
            int len = strlen(s + 1);
            reverse(s + 1, s + 1 + len);
            suffixHash[i][0] = len;
            ULL x = 0;
            for(int j = 1; j <= len; ++j){
                x = x * MOD + s[j];
                suffixHash[i][j] = x % P;
            }
            hashVal[i] = x % P;
        }            
        for(int i = 1; i <= n; ++i){
            ++timStp;
            int sz = static_cast<int>(suffixHash[i][0]);
            for(int j = 1; j <= sz; ++j){
                int curHash = suffixHash[i][j];
                if(vis[curHash] != timStp) vis[curHash] = timStp;
            }
            for(int j = 1; j <= n; ++j){
                isSuffix[i][j] = vis[hashVal[j]] == timStp;
            }
        }
        int q; scanf("%d", &q);
        while(q--){
            int op, x; scanf("%d%d", &op, &x);
            if(op == 1){
                int y; scanf("%d", &y);
                w[x] = y;
            }
            else{
                int ans = 0;
                for(int i = 1; i <= n; ++i){
                    if(w[i] <= w[x] && isSuffix[i][x]) ++ans;
                }
                printf("%d\n", ans);
            }
        }
        
    }
    return 0;
}
