//
//  Created by TaoSama on 2016-07-30
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

typedef long long LL;
LL x, y, z, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> x >> y >> z >> k) {
        LL xl = 1, yl = 1, zl = 1;
        k = min(x + y + z - 3, k);

        LL ans = 1;
        while(k > 0) {
            if(k > 0 && xl < x) {
                ans += yl * zl;
                ++xl;
                --k;
            }
            if(k > 0 && yl < y) {
                ans += xl * zl;
                ++yl;
                --k;
            }
            if(k > 0 && zl < z) {
                ans += yl * xl;
                ++zl;
                --k;
            }
        }
//      pr(xl); pr(yl); prln(zl);
        cout << ans << endl;
    }
    return 0;
}
