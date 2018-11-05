
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string d2b(int x, int d) {
    string ret;
    for (; x; x /= 2) ret += char(x % 2 + '0');
    if(d == -1) {
        return ret;
    }
    for(int i = ret.size(); i < d; ++i) ret += char('0');
    return ret;
}

int f[70][70][70][2];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        string sc = d2b(c, -1);
        int d = sc.size();

        // cout << d2b(a, d) << endl;
        // cout << d2b(b, d) << endl;
        // cout << "fuck" << endl;
        int onesa = __builtin_popcount(a);
        int onesb = __builtin_popcount(b);
        // cout << d << ' ' << onesa << ' ' << onesb << endl;
        memset(f, 0, sizeof f);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                f[1][i][j][i + j >> 1] = sc[0] - '0' == (i + j & 1);
            }
        }
        for (int i = 1; i < d; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= i; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        for (int a = 0; a < 2; ++a) {
                            for (int b = 0; b < 2; ++ b) {
                                f[i + 1][j + a][k + b][a + b + l >> 1] += f[i][j][k][l] * (sc[i] - '0' == (a + b + l & 1));
                            }
                        }
                    }
                }
            }
        }
        cout << f[d][onesa][onesb][0] << endl;
    }
    return 0;
}
