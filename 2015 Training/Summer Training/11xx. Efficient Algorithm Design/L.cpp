//
//  Created by TaoSama on 2015-07-31
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

int n, a[N << 1], b[N << 1];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];
        memcpy(a + n + 1, a + 1, sizeof(int) * n);
        memcpy(b + n + 1, b + 1, sizeof(int) * n);

        bool can = false;
        int fuel = 0, st = 1;
        for(int i = 1; i <= n << 1; ++i) {
            if(i == n + st) {
                can = true;
                break;
            }
            if(st == n + 1) break;
            fuel += a[i];
            if(fuel >= b[i]) fuel -= b[i];
            else {
                fuel = 0;
                st = i + 1;
            }
        }
        cout << "Case " << ++kase << ": ";
        if(!can) cout << "Not possible\n";
        else cout << "Possible from station " << st << '\n';
    }
    return 0;
}
