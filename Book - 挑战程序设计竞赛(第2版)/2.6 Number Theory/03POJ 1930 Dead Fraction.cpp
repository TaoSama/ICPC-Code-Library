//
//  POJ 1930 Dead Fraction
//
//  Created by TaoSama on 2015-03-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string s;

int pow(int n) {
    int ret = 1;
    for(int i = 1; i <= n; ++i)
        ret *= 10;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        if(s == "0") break;
        s = s.substr(2, s.size() - 5);
        int n = atoi(s.c_str()), sz = s.size();
        if(n == 0) cout << "0/1" << endl;
        else {
            int ansx, ansy = INF;
            for(int i = 1; i <= sz; ++i) {
                string xx = s.substr(0, sz - i);
                int x = n - atoi(xx.c_str());
                int y = pow(sz) - pow(sz - i);
                int gcd = __gcd(x, y);
                x /= gcd; y /= gcd;
                if(y < ansy) ansx = x, ansy = y;
            }
            cout << ansx << '/' << ansy << endl;
        }
    }
    return 0;
}
