
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

double A[5][5];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 0; i <= 4; ++i) A[0][i] = 1;
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            cin >> A[i][j];
        }
    }
    {
        stringstream ss;
        string line; getline(cin, line);

        getline(cin, line);
        ss << line;
        double r1 = 1;
        int last = 0;
        for(int i = 1, x; ss >> x; ++i) {
            r1 *= A[last][x];
            last = x;
        }
        cout << fixed << setprecision(8) << r1 << endl;
    }
    {
        stringstream ss;
        string line; getline(cin, line);

        ss << line;
        double r1 = 1;
        int last = 0;
        for(int i = 1, x; ss >> x; ++i) {
            r1 *= A[last][x];
            last = x;
        }
        cout << fixed << setprecision(8) << r1 << endl;
    }

    for(int i = 1; i <= 2; ++i) {
        int x; cin >> x;
        double e = (A[x][x]) / (1 - A[x][x]) + 1;
        cout << fixed << setprecision(8) << e << endl;
    }
    
    return 0;
}
