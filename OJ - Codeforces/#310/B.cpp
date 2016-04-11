//
//  Created by TaoSama on 2015-06-27
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

int n, a[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        if(n == 1) {
            cout << "YES\n";
            continue;
        }
        bool ok = false;
        for(int t = 0; t <= 1e7; ++t) {
            int x = (a[1] + t) % n, y = ((a[2] - t) % n + n) % n;
            if(x == 0 && y == 1) {
                bool can = true;
                for(int i = 3; i <= n; i ++) {
                    if(i & 1) {
                        int x = (a[i] + t) % n;
                        if(x != i - 1) {
                            can = false;
                            break;
                        }
                    } else {
                        int y = ((a[i] - t) % n + n) % n;
                        if(y != i - 1) {
                            can = false;
                            break;
                        }
                    }
                }
                if(can) {
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
