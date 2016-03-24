//
//  Created by TaoSama on 2015-11-30
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

int n, a, b, c;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &a, &b, &c) == 4) {
        int ans = 0, sum = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            sum += x;
            if(sum >= a && sum < b) ans += 2;
            else if(sum >= b && sum < c) ans += 3;
            else if(sum >= c) ans += 4;
            else continue;
            sum = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
