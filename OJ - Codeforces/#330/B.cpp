//
//  Created by TaoSama on 2015-11-09
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

int n, k, a[N], b[N];
long long ten[N] = {1};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 10; ++i) ten[i] = ten[i - 1] * 10;

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n / k; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n / k; ++i) scanf("%d", b + i);
        long long ans = 1;
        for(int i = 1; i <= n / k; ++i) {
            long long cnt = (ten[k] - 1) / a[i];
            if(b[i]) {
                cnt += 1; //000
                //(d)9999 - (d-1)99999
                cnt -= ((b[i] + 1) * ten[k - 1] - 1) / a[i] - (b[i] * ten[k - 1] - 1) / a[i];
            } else {
                cnt -= (ten[k - 1] - 1) / a[i];
            }
//          pr(i); prln(cnt);
            ans = ans * cnt % MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
