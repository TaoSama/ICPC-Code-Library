
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int cnt[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[i] = 0;
        }
        long long ans  = 0;
        for(int i = 2; i <= n; ++i) {
            cnt[i] = cnt[i - 1];
            if(a[i] < a[i - 1]) {
                if(a[i] == 0) {
                    ans = -1;
                    break;
                }
            }
            int t = a[i];
            while(cnt[i] > 0 && t / 2 >= a[i - 1]) {
                --cnt[i];
                t >>= 1;
            }
            t = a[i];
            while(t < a[i - 1]) {
                ++cnt[i];
                t <<= 1;
            }
        }
        if(ans != -1) for(int i = 1; i <= n; ++i) ans += cnt[i];
        // for(int i= 1;i<=n;++i) cout << i << "=" << cnt[i]<<endl;
        cout << ans << endl;
    }
    return 0;
}
