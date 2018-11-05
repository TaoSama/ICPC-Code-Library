
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], to[N];
char s[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        static int kase = 0;
        if(a[1] == 0 || a[n] == 0) {
            cout << "Case #" << ++kase << ": " << "IMPOSSIBLE\n";
            continue;
        }
        int cur = 1;
        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            while(a[i] --) to[cur++] = i;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, abs(i - to[i]) + 1);
        for(int i = 1; i <= ans; ++i) {
            for(int j = 1; j <= n; ++j) s[i][j] ='.';
        }
        for(int i = 1; i <= n; ++i) {
            if(to[i] < i) {
                int r = 1;
                for(int j = i; j > to[i]; --j) s[r++][j] = '/';
            }
            else if(to[i] > i) {
                int r = 1;
                for(int j = i; j < to[i]; ++j) s[r++][j] = '\\';
            }
        }
        cout << "Case #" << ++kase << ": " << ans << '\n';
        for(int i = 1; i <= ans; ++i) {
            for(int j = 1; j <= n; ++j) {
                cout << s[i][j];
            }
            cout << '\n';
        }

    }
    return 0;
}
