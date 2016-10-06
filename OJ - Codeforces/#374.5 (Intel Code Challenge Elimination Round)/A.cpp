//
//  Created by TaoSama on 2016-10-01
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

int t, m, h;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d:%d", &t, &m, &h) == 3) {
        int ans = 0;
        if(h >= 60) h -= 60;
        if(t == 12) {
            if(m > 12) m -= (m / 10) * 10;
            if(m == 0) m += 10;
        } else {
            if(m > 23) m -= m / 10 * 10;
        }
        printf("%02d:%02d\n", m, h);
    }

    return 0;
}
