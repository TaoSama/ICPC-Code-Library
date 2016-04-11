//
//
//
//  Created by TaoSama on 2015-04-15
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

long long A, B, n;

double calc(long long a, long long b, long long c) {
    return (-b + sqrt(b * b - 4 * a * c)) / 2.0 / a;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d%I64d", &A, &B, &n) == 3) {
        for(int i = 1; i <= n; ++i) {
            long long l, t, m; scanf("%I64d%I64d%I64d", &l, &t, &m);
            long long al = A + (l - 1) * B;
            long long ans;
            if(t < al) ans = -1;
            else {
                long long r = calc(B, 2 * A - B, -2 * A * l - B * l * l
                                   + 2 * A + 3 * B * l - 2 * B - 2 * m * t);
                //cout << "r: " << r << endl;
                ans = (t - A)/B + 1;
                if(ans > r) ans = r;
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
