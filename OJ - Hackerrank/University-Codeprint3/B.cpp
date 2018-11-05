
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int e[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    cin >> m;
    while(m--) {
        int x, y, d;
        cin >> x >> y >> d;
        queue<pair<pair<int, int>, int>> q;
        q.push({{x, y}, d});
        vector<vector<int>> vis(n + 1, vector<int>(n + 1));
        while(q.size()) {
            int x, y; tie(x, y) = q.front().first;
            int d = q.front().second;
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;
            e[x][y] += d;
            if(d == 1) continue;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    if(i == 0 && j == 0) continue;
                    int nx = x + i, ny = y + j;
                    if(nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
                    q.push({{nx, ny}, d - 1}); 
                }
            }
        }
    }
    cout << *max_element(e[0], e[0] + N * N) << endl; 
    return 0;
}
