//
//  Created by TaoSama on 2016-02-04
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
LL a[3], l;

LL gao(LL a, LL b, LL c, LL x) {
    if(a + x < b + c) return 0;
    LL yz = min(a - b - c + x, l - x);
    return (yz + 2) * (yz + 1) / 2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a[0] >> a[1] >> a[2] >> l) {
        LL ans = (l + 3) * (l + 2) * (l + 1) / 6; //C(l+4-1,4-1);
        //a+x>=b+y+c+z => y+z<=a-b-c+x
        //x+y+z<=l     => y+z<=l-x
        //C(y+z+3-1,3-1)
        for(int i = 0; i < 3; ++i)
            for(LL x = 0; x <= l; ++x)
                ans -= gao(a[i], a[(i + 1) % 3], a[(i + 2) % 3], x);
        cout << ans << '\n';
    }
    return 0;
}
