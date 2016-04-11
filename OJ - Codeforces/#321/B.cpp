//
//  Created by TaoSama on 2015-09-23
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

int n, m;
typedef pair<int, int> P;
P a[N];
int deq[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);
        int l = 1;
        long long sum = 0, ans = 0;
        for(int i = 1; i <= n; ++i) {
            sum += a[i].second;
            deq[i] = i;
            while(i > l
                    && a[deq[i]].first - a[deq[l]].first >= m) sum -= a[deq[l++]].second;
//          printf("%d\n", sum);
            ans = max(ans, sum);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
