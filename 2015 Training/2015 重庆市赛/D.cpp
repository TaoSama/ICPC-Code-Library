//
//  Created by TaoSama on 2015-11-19
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

LL n, a, b, c, OFF = 1e5;
string l, w, h;

LL ten(int x) {
    LL ret = 1;
    for(int i = 1; i <= x; ++i) ret *= 10;
    return ret;
}

void handle(string &l, LL& a) {
    if(l.find('.') == string::npos) {
        a = atoi(l.c_str()) * OFF;
        return;
    }
    int p = l.find('.'); l.erase(p, 1);
    a = atoi(l.c_str()) * ten(5 - (l.size() - p));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> l >> w >> h;
        handle(l, a);
        handle(w, b);
        handle(h, c);
        LL each = __gcd(a, __gcd(b, c));
        LL ans = a * b * c / (each * each * each);
        cout << ans << '\n';
    }
    return 0;
}
