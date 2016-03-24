//
//  Created by TaoSama on 2015-07-27
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

bool isLucky(int n) {
    while(n) {
        if(n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}

bool check(int n) {
    for(int i = 4; i <= n; ++i) {
        if(n % i == 0 && isLucky(i)) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
//      cout << isLucky(4) << endl;
        cout << (check(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}
