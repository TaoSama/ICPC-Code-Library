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

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n) {
        if(kase++) cout << '\n';
        cout << 2 << ' ' << n << ' ' << n << '\n';
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < n; ++j)
                cout << char((j >= 26 ? 'A' - 26 : 'a') + j);
            cout << '\n';
        }
        cout << '\n';
        for(int i = 0; i < n; ++i)
            cout << string(n, (i >= 26 ? 'A' - 26 : 'a') + i) << '\n';
    }
    return 0;
}
