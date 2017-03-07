//
//  Created by TaoSama on 2017-01-28
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        int ans = x;
        if(x >= 38) {
            int d = x % 10;
            if(d > 2 && d < 5) ans = x / 10 * 10 + 5;
            else if(d > 7 && d < 10) ans = (x / 10 + 1) * 10;
        }
        cout << ans << endl;
    }

    return 0;
}