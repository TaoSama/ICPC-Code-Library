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

typedef long long LL;

LL k, a, b, c[35];

void init() {
    c[0] = 1;
    for(int i = 1; i <= 30; ++i) c[i] = 3 * c[i - 1];
}

LL get(LL k, LL i) {
    if(i <= 0) return 0;
    if(!k) return 1;
    if(i >= 1 << k - 1) return 2 * c[k - 1] + get(k - 1, i - (1 << k - 1));
    else return 2 * get(k - 1, i);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    init();
    while(t--) {
        cin >> k >> a >> b;
        cout << "Case " << ++kase << ": " << get(k, b) - get(k, a - 1) << '\n';
    }
    return 0;
}
