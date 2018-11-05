
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef unsigned long long ULL;
int n;
char s[N];
bool isPalindrome[N][N];
int cnt[N], f[N][N];

int dfs(int l, int r){
    int& ret = f[l][r];
    if(ret >= 0) return ret;
    if(l > r || !isPalindrome[l][r]) return ret = 0;
    int len = r - l + 1;
    len /= 2;
    ret = min(dfs(l, l + len - 1), dfs(r - len + 1, r)) + 1;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%s", s + 1) == 1){
        n = strlen(s + 1);
        memset(isPalindrome, 0, sizeof isPalindrome);
        for(int i = 1; i <= n; ++i) isPalindrome[i + 1][i] = isPalindrome[i][i] = true;
        for(int L = 1; L < n; ++L) {
            for(int i = 1; i + L <= n; ++i) {
                int j = i + L;
                if(s[i] == s[j]) isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                else isPalindrome[i][j] = false;
            }
        }

        memset(cnt, 0, sizeof cnt);
        memset(f, -1, sizeof f);
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                // printf("%d %d\n", i, j);
                dfs(i, j);
                ++cnt[f[i][j]];
            }
        }

        for(int i = n - 1; i >= 1; --i) cnt[i] += cnt[i + 1];
        for(int i = 1; i <= n; ++i) printf("%d%c", cnt[i], " \n"[i == n]);
    }
        
    return 0;
}
