//
//  Created by TaoSama on 2015-08-22
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

long double s, a, b, c;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> a >> b >> c) {
        if(a + b + c < 1e-10) {
            cout << fixed << setprecision(12) << s << ' ' << 0 << ' ' << 0 << '\n';
            continue;
        }
        long double x = s * a / (a + b + c);
        long double y = s * b / (a + b + c);
        long double z = s - x - y;
        cout << fixed << setprecision(12) << x << ' ' << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}
