//
//  Created by TaoSama on 2015-07-17
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a, b, c, d;
char op;
string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        a = s[0] - '0';
        b = s[2] - '0';
        c = s[4] - '0';
        d = s[6] - '0';
        op = s[3];

        int lcm = b * d / __gcd(b, d);
        a *= lcm / b;
        c *= lcm / d;

        a = op == '+' ? a + c : a - c;

//      prln(a);

        int gcd = abs(__gcd(a, lcm));
        if(a == 0) cout << "0\n";
        else {
            cout << a / gcd;
            if(lcm / gcd != 1) cout << '/' << lcm / gcd;
            cout << '\n';
        }
    }
    return 0;
}
