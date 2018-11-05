
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 5;

int n, m, q;
int a[500][800];
bool isFreeX[500];

inline int inv(int x) {return x * x * x % MOD;}

int gauss(int n, int m, int q) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) swap(a[maxR], a[r]);

        if(!a[r][c]) { --r; isFreeX[c] = true; continue;}

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            if(a[i][c]) {
                int delta = a[i][c] * inv(a[r][c]);
                for(int j = c; j < m + q; ++j) {
                    a[i][j] -= delta * a[r][j];
                    a[i][j] %= MOD;
                    if(a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
    }

    //at last, r is rank, m - r is the number of freeX
    return r;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        char s[505]; scanf("%s", s);
        for(int j = 0; j < m; ++j){
            int x = s[j] - 'a';
            a[j][i] = x;
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        char s[505]; scanf("%s", s);
        for(int j = 0; j < m; ++j) a[j][n + i] = s[j] - 'a';
    }
    int r = gauss(m, n, q);

    auto quick = [](int x, int n, int m){
        int ret = 1;
        for(; n; n >>= 1){
            if(n & 1) ret = 1ll * ret * x % m;
            x = 1ll * x * x % m;
        }
        return ret;
    };
   
    // cout << "ran = " << r << " free = " << n - r << endl;
    int ans = quick(5, n - r, 1000000007); 
    for(int i = 0; i < q; ++i){
        bool ok = true;
        for(int j = r; j < m; ++j) ok &= a[j][n + i] == 0;
        printf("%d\n", ok ? ans : 0);
    }
    return 0;
}
