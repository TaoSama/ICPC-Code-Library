//
//  Created by TaoSama on 2015-07-23
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

bool balance(int& w) {
    int w1, d1, w2, d2;
    bool sub1 = true, sub2 = true;
    if(cin >> w1 >> d1 >> w2 >> d2) {}
	else return false;
//	cout << w1 << ' ' << d1 << ' ' << w2 << ' ' << d2 << endl;
    if(!w1) sub1 = balance(w1);
    if(!w2) sub2 = balance(w2);
	w = w1 + w2;

    return sub1 && sub2 && w1 * d1 == w2 * d2;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t, w; cin >> t;
    int kase = 0;
    while(t--) {
        if(kase++) cout << '\n';
        if(balance(w)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
