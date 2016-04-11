//
//  POJ 3045 Cow Acrobats
//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
struct Cow {
    int w, s;
    bool operator < (const Cow& rhs) const {
        return w + s < rhs.w + rhs.s;
    }
} a[50005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].w, &a[i].s);
    sort(a + 1, a + 1 + n);
    int ans = -INF, sum = 0;
    for(int i = 1; i <= n; ++i){
		ans = max(ans, sum - a[i].s);
		sum += a[i].w;
    }
    printf("%d\n", ans);
    return 0;
}
