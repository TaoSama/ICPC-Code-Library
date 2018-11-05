
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
char s[N];
int cnt[N][26];


int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%s", &n, &q, s + 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 26; ++j) cnt[i][j] = cnt[i - 1][j];
            cnt[i][s[i] - 'A']++;
        }
        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            for(int j = 0; j < 26; ++j) {
                if(cnt[r][j] - cnt[l - 1][j]) {
                    printf("%d\n", cnt[r][j] - cnt[l - 1][j]);
                    break;
                }
            }
        }
    }
    return 0;
}
