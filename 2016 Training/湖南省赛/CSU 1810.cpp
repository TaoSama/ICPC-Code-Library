//
//  Created by TaoSama on 2016-09-05
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

/*
1
21
321
4321
54321

12
132
1432
15432

123
1243
12543

1234
12354

12345
*/

typedef long long LL;
int n;
char s[N];
LL ten[N], sumTen[N];
const int tenInv = 700000005, twoInv = 500000004;

LL ksm(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    sumTen[0] = ten[0] = 1;
    for(int i = 1; i < N; ++i) {
        ten[i] = ten[i - 1] * 10 % MOD;
        sumTen[i] = (sumTen[i - 1] + ten[i]) % MOD;
    }

    while(scanf("%d%s", &n, s + 1) == 2) {
        LL seqLast = 0, seqSum = 0, revLast = 0, revSum = 0;

        for(int i = 1; i <= n; ++i) {
            s[i] -= '0';
            seqLast = (seqLast + s[i] * ten[n - i]) % MOD;
            seqSum = (seqSum + seqLast) % MOD;
            revLast = (revLast * tenInv % MOD + s[i] * ten[n - 1]) % MOD;
            revSum = (revSum + revLast) % MOD;
        }

        LL ans = 1LL * n * (n + 1) % MOD * twoInv % MOD * seqLast % MOD;
        ans = (ans - seqSum + revSum) % MOD;

        for(int i = 1; i < n; ++i) {
            seqSum = (seqSum - (n - i + 1) * s[i] * ten[n - i]) % MOD;
            revSum = (revSum - s[i] * sumTen[n - i]) % MOD;
            revSum = revSum * tenInv % MOD;
            ans = (ans - seqSum + revSum) % MOD;
        }
        ans = (ans + MOD) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
