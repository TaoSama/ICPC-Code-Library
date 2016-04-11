//
//  Created by TaoSama on 2015-09-22
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

int n, k;
int a[N];
int deq[N], deqv[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            a[i + n] = a[i];
        }

        int l = 0, r = 0;
        int L = 1, R = 1, ans = a[1], sum = 0;
        for(int i = 2; i <= n; ++i)
            if(a[i] > ans) ans = a[i], L = R = i;
        for(int i = 1; i <= n << 1; ++i) {
            sum += a[i];
            while(l < r && deqv[r - 1] >= sum) --r;
            deq[r] = i; deqv[r] = sum; ++r;
            if(i > k) {
                if(i != deq[l]) {
                    if(sum - deqv[l] > ans || sum - deqv[l] == ans
                            && i - deq[l] < R - L + 1) {
                        ans = sum - deqv[l];
                        L = deq[l] + 1;
                        R = i;
                    }
                }
                if(deq[l] == i - k) ++l;
            }
        }
        printf("%d %d %d\n", ans, (L - 1) % n + 1, (R - 1) % n + 1);
    }
    return 0;
}
