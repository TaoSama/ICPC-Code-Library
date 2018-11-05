
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q, nxt[N];
char s[N], t[N];

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < m) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int ans[N][N];
int kmp(int st) {
    int i = st, j = 0, ret = 0;
    while(i < n) {
        ans[st][i] = ret;
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == m) {
            ans[st][i - 1] = ++ret ;
        }
        // cout << st << ' ' << i << ' ' << ret << endl;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m >> q) {
        cin >> s >> t;
        getNxt();
        for(int i = 0; i < n; ++i) {
            kmp(i);
        }
        for(int i = 0; i < q; ++i) {
            int l, r; cin >> l >> r;
            --l; --r;
            cout << ans[l][r] << '\n';
        }
    }
    return 0;
}
