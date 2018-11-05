
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int A = N + N, B = N * N;

int a[A][B], ans[B];
int n, m;
int xorGauss() {
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; continue;}
        swap(a[p], a[r]);
        for(int i = 0; i < n; ++i) {
            if(i != r && a[i][c]) {
                for(int j = c; j <= m; ++j)
                    a[i][j] ^= a[r][j];
            }
        }
    }
    for(int i = r; i < n; ++i) if(a[i][m]) return -1;
    // memset(ans, 0, sizeof ans);  //not necessary
    for(int i = r - 1; ~i; --i)
        for(int j = 0; j < m; ++j)
            if(a[i][j]) {ans[j] = a[i][m]; break;}
    return r;
}

int r, c;
int row[N], col[N];
int cof[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> r >> c) {
        for(int i = 0; i < r; ++i) cin >> row[i];
        for(int i = 0; i < c; ++i) cin >> col[i];
        memset(cof, 0, sizeof cof);
        int ok = 0;
        for(int b = 0; b < 30; ++ b) {
            n = 0, m = r * c;
            memset(a, 0, sizeof a);
            for(int i = 0; i < r; ++i) {
                for(int j = 0; j < c; ++j) {
                    a[n][i * c + j] = 1; 
                }
                a[n++][m] = row[i] >> b & 1;
            }
            for(int j = 0; j < c; ++j) {
                for(int i = 0; i < r; ++i) {
                    a[n][i * c + j] = 1;
                }
                a[n++][m] = col[j] >> b & 1;
            }
            ok = xorGauss();
            if(ok == -1) break;
            for(int i = 0; i < m; ++i) {
                cof[i / c][i % c] |= ans[i] << b;
            }
        }
        if(ok == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < r; ++i) {
                for(int j = 0; j < c; ++j) {
                    cout << cof[i][j] << " \n"[j == c - 1];
                }
            }
        }
        // for(int i = 0; i < r; ++i) {
            // int x = 0;
            // for(int j = 0; j < c; ++j) x ^= cof[i][j];
            // cout << x <<  ' ';
        // }
        // cout << endl;
        // for(int i = 0; i < c; ++i) {
            // int x = 0;
            // for(int j = 0; j < r; ++j) x ^= cof[j][i];
            // cout << x <<  ' ';
        // }
        // cout << endl;
    }
    return 0;
}
