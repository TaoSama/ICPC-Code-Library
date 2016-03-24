//
//  Created by TaoSama on 2015-08-05
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

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) {
            if(i == 1)
                cout << abs(a[1] - a[2]) << ' ' << abs(a[1] - a[n]) << '\n';
            else if(i == n)
                cout << abs(a[n] - a[n - 1]) << ' ' << abs(a[1] - a[n]) << '\n';
            else {
                cout << min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) << ' ' <<
                     max(abs(a[i] - a[1]), abs(a[i] - a[n])) << '\n';
            }
        }
    }
    return 0;
}
