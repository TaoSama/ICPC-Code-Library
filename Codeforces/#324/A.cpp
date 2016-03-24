//
//  Created by TaoSama on 2015-10-07
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

int n, k;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        if(k == 10) {
            if(n == 1) cout << "-1\n";
            else {
                cout << 10 << string(n - 2, '0') << '\n';
            }
            continue;
        }
        for(int i = 1; i <= n; ++i) {
            if(i == 1) cout << k;
            else cout << 0;
        }
        cout << '\n';
    }
    return 0;
}
