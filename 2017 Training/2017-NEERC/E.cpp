
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char a[N], b[N];

bool check(int x) {
    vector<int> lft(n + 1, x);
    int j = 1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] != 'P') continue; 
        for(; j <= n && a[j] != '*'; ++j); 
        if(j > n) return true;
        // cout << "*= " << j << " P= " << i << endl;
        if(i > j) {
            // cout << lft[i] << ' ' << i - j << endl;
            if(lft[i] < i - j) return false;
            int a = lft[i] - 2 * (i - j);
            int b = (lft[i] - (i - j)) / 2;
            j = i + max({0, a, b}) + 1;
            // cout << "here" << endl;
        }
        else {
            if(lft[i] >= j - i) {
                lft[i] -= j - i;
                for(; lft[i] > 0 && j + 1 <= n; ) {
                    ++j, --lft[i];
                    if(a[j] == '*') a[j] = '.';
                }
                ++j;
            }
        }
        // cout << "eat then " << j << endl;
    }
    for(; j <= n && a[j] != '*'; ++j);
    if(j <= n && a[j] == '*') return false;
    return true;
}    

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> (b + 1)) {
        int l = 1, r = 2 * n, ans = -1;
        // cout << check(3) << endl;
        // return 0;
        while(l <= r) {
            int m = (l + r) / 2;
            bool ok = false;
            for(int i = 1; i <= n; ++i) a[i] = b[i];
            ok |= check(m);
            for(int i = 1; i <= n; ++i) a[i] = b[n - i + 1];
            ok |= check(m);
            if(ok) ans = m, r = m - 1;
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
