//
//  Created by TaoSama on 2015-07-22
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

int a1, b1, a2, b2, a3, b3;

bool judge() {
    //23 -
    if(a2 + a3 <= a1 && max(b2, b3) <= b1) return true; //u d
    if(max(a2, a3) <= a1 && b2 + b3 <= b1) return true; //l r
    //23 |
    if(b2 + b3 <= a1 && max(a2, a3) <= b1) return true;
    if(max(b2, b3) <= a1 && a2 + a3 <= b1) return true;
    //2- 3|
    if(a2 + b3 <= a1 && max(b2, a3) <= b1) return true;
    if(max(a2, b3) <= a1 && b2 + a3 <= b1) return true;
    //2| 3-
    if(b2 + a3 <= a1 && max(a2, b3) <= b1) return true;
    if(max(b2, a3) <= a1 && a2 + b3 <= b1) return true;

    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a1 >> b1) {
        cin >> a2 >> b2;
        cin >> a3 >> b3;
        if(a1 > b1) swap(a1, b1);
        if(a2 > b2) swap(a2, b2);
        if(a3 > b3) swap(a3, b3);

        cout << (judge() ? "YES" : "NO") << '\n';
    }
    return 0;
}
