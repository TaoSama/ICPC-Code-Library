//
//  Created by TaoSama on 2015-08-05
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        map<long long, int> cnt1, cnt2;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            cnt1[a[i]]++;
        }

        long long sum = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] % k == 0) {
                int p1 = a[i] / k;
                int x1 = cnt2[p1];
                cnt2[a[i]]++;
                long long p2 = 1LL * a[i] * k;
                int x2 = cnt1[p2] - cnt2[p2];
                sum += 1LL * x1 * x2;
            } else cnt2[a[i]]++;
        }
        cout << sum << '\n';
    }
    return 0;
}
