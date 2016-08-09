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

int x, y, z, x1, y1, z1;
int a[7];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> x >> y >> z >> x1 >> y1 >> z1) {
        for(int i = 1; i <= 6; ++i) cin >> a[i];
        int ans = 0;
        if(y < 0) ans += a[1];
        if(y > y1) ans += a[2];
        if(z < 0) ans += a[3];
        if(z > z1) ans += a[4];
        if(x < 0) ans += a[5];
        if(x > x1) ans += a[6];
        cout << ans << endl;
    }

    return 0;
}
