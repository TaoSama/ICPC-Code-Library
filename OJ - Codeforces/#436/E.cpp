
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[105][2005];
pair<int, int> p[105][2005];
pair<int, pair<pair<int, int>, int>> a[105];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            int t, d, p;
            cin >> t >> d >> p;
            a[i] = {d, {{t, p}, i}};
        }
        sort(a + 1, a + 1 + n);

        memset(f, 0xc0, sizeof f);
        f[0][0] = 0;
        p[0][0] = {-1, -1};
        for(int i = 1; i <= n; ++i) {
            int d = a[i].first, t, v;
            tie(t, v) = a[i].second.first;
            int id = a[i].second.second;
            for(int j = 0; j <= 2000; ++j) {
                if(f[i][j] < f[i - 1][j]) {
                    f[i][j] = f[i - 1][j];
                    p[i][j] = {j, 0};
                }
                if(j + t < d) {
                    if(f[i][j + t] < f[i - 1][j] + v) {
                        f[i][j + t] = f[i - 1][j] + v; 
                        p[i][j + t] = {j, id};
                    }
                }
            }
        }
        int t = max_element(f[n], f[n] + 2000 + 1) - f[n];
        int ans = f[n][t];
        vector<int> choose;
        for(int i = n; i >= 1; --i) {
            int o = p[i][t].second;
            if(o) choose.push_back(o);
            t = p[i][t].first;
        }
        cout << ans << endl;
        cout << choose.size() << endl;
        reverse(choose.begin(), choose.end());
        for(int x : choose) cout << x << ' '; cout << endl;
    }
    return 0;
}
