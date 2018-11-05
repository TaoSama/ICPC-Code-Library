
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int d[][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, r, k;
    while(cin >> n >> m >> r >> k) {
        // vector<vector<int>> v(n + 1, vector<int>(m + 1));
        // for(int i = 1; i <= n - r + 1; ++i) {
            // for(int j = 1; j <= m - r + 1; ++j) {
                // for(int k = 0; k < r; ++k) {
                    // for(int l = 0; l < r; ++l) {
                        // ++v[i+k][j+l];
                    // }
                // }
            // }
        // }
        // for(int i = 1; i <= n; ++i) {
            // for(int j = 1; j <= m; ++j) {
                // cout << setw(2) << v[i][j] << ' ';
            // }
            // cout << endl;
        // }
        auto get = [&](int x, int y) {
            int lx = max(1, x - r + 1);
            int ly = max(1, y - r + 1);
            x = min(x, n - r + 1);
            y = min(y, m - r + 1);
            // cout << lx << ' ' << ly << ' ' << x << ' ' << y << endl;
            return 1ll * (x - lx + 1) * (y - ly + 1);
        };
        priority_queue<pair<long long, pair<int, int>>> q;
        int sx = (n + 1) / 2, sy = (m + 1) / 2;
        q.push({get(sx, sy), {sx, sy}});
        set<pair<int, int>> vis; vis.insert({sx, sy});
        long long sum = 0;
        for(int i = 1; i <= k; ++i) {
            auto s = q.top(); q.pop();
            sum += s.first;
            int x, y; tie(x, y) = s.second;
            for(int j = 0; j < 4; ++j) {
                int nx = x + d[j][0], ny = y + d[j][1];
                if(nx < 1 || nx > n || ny < 1 || ny > m || vis.count({nx, ny})) continue;
                vis.insert({nx, ny});
                q.push({get(nx, ny), {nx, ny}});
            }
        }
        // cout << sum << endl;
        cout << fixed << setprecision(20) << 1.0 * sum / (n - r + 1) / (m - r + 1) << endl;
    }
    return 0;
}
