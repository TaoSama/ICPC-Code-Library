//
//  Created by TaoSama on 2016-08-07
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
LL p, delta;
LL ten[20];
LL get(LL x, int i) {
    return x / ten[i] % 10;
}
void change(LL& x, int i, int y) {
    int d = get(x, i);
    x -= d * ten[i];
    x += y * ten[i];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> p >> delta;
    ten[0] = 1;
    for(int i = 1; i <= 18; ++i) ten[i] = ten[i - 1] * 10;

    LL x = p;
    LL ans = x;
    for(int i = 0; i < 18; ++i) {
        int d = get(x, i);
        if(d == 9) {
            ans = x;
            continue;
        }
        if(d < 9 && x >= ten[i + 1]) {
            change(x, i, 9);
            x -= ten[i + 1];
        } else break;

        if(p - x <= delta) ans = x;
        else break;
//      prln(x);
    }
    cout << ans << endl;

    return 0;
}
