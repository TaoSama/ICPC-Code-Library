//
//  Created by TaoSama on 2017-04-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int x, y, a, b;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        int ans = 0;
        set<pair<int, int>> s1, s2;
        bool loop = x == 1 || y == 1;
        while(a >= x || b >= y) {
            if(s1.count({a, b})) {loop = true; break;}
            s1.insert({a, b});
            int delta = a / x + b / y;
            a = a % x + delta;
            b = b % y + delta;
            ans += delta;
        }
        if(loop) cout << "INF\n";
        else cout << ans << endl;
    }


    return 0;
}
