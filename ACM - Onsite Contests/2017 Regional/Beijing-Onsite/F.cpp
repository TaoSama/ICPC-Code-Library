
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char a[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<vector<int>> vis(n, vector<int>(n));

        static const int oneStep[2][2] = {{0, 1}, {1, 0}};
        static const int manyStep[2][2] = {{1, -1}, {-1, 1}};
        static const int snakeStep[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto go = [&](int& x, int &y, int stp, int& last) {
            if(stp == 1) {
                for(int i = 0; i < 2; ++i) {
                    int j = (i + last) % 2;
                    int nx = x + manyStep[j][0], ny = y + manyStep[j][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {}
                    else {
                        last = j ^ 1;
                        x = nx; y = ny;
                        return true;
                    }
                }
                return false;
            }
            else if(stp == 0) {
                for(int i = 0; i < 2; ++i) {
                    int j = (i + last) % 2;
                    int nx = x + oneStep[j][0], ny = y + oneStep[j][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {}
                    else {
                        last = j ^ 1;
                        x = nx; y = ny;
                        return true;
                    }
                }
                return false;
            }
            
            for(int i = 0; i < 4; ++i) {
                int j = (i + last) % 4;
                int nx = x + snakeStep[j][0], ny = y + snakeStep[j][1];
                // cout <<"cc " << nx << ny << endl;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {}
                else {
                    last = j;
                    x = nx; y = ny;
                    return true;
                }
            }
            return false;
        };
        
        string seqs;
        int x = 0, y = 0, last = 0, ver = 0;
        seqs += a[x][y];
        vis[x][y] = 1;
        bool canGo = true;
        while(canGo) {
            canGo = go(x, y, 1, last) || go(x, y, 0, ver);
            if(canGo) {
                vis[x][y] = 1;
                seqs += a[x][y];
            }
        }
        // cout << seqs << endl;

        int idx = 0;
        x = 0, y = 0, last = 0;
        vis = vector<vector<int>>(n, vector<int>(n));
        vis[x][y] = 1;
        a[x][y] = seqs[idx];
        canGo = true;
        while(canGo) {
            canGo = go(x, y, 2, last);
            // cout << x << ' ' << y << endl;
            if(canGo) {
                a[x][y] = seqs[++idx];
                vis[x][y] = 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << a[i][j]; 
                if(j + 1 == n) cout << '\n';
            }
        }
    }
    return 0;
}
