
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int need = (n + 8) / 9;
        int x = 500, y = 500;
        int cnt[3][3] = {};
        while(true) {
            cout << x << ' ' << y << endl; 
            int px, py; cin >> px >> py;
            if(px == 0 && py == 0) break;
            cnt[px - x + 1][py - y + 1] = 1;
            int sum = 0;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    sum += cnt[i + 1][j + 1];
                }
            }
            if(sum == 9) {
                memset(cnt, 0, 9 << 2);
                x += 3;
            }
        }

    }
    return 0;
}
