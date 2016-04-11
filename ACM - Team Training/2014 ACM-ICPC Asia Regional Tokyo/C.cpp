//
//  Created by TaoSama on 2015-12-04
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

typedef pair<int, int> P;

int n, m;
P a[1005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= m; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + m);

        int l = 0, r = 0, ans = n + 1;
        for(int i = 1; i <= m; ++i) {
            if(a[i].first <= r) r = max(r, a[i].second);
            else {
                ans += r - l << 1;
                l = a[i].first, r = a[i].second;
            }
        }
        ans += r - l << 1;
        printf("%d\n", ans);
    }
    return 0;
}
