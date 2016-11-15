#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
LL a, b, c;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
    cin >> a >> b >> c;
    LL sysdif = a + b - 2 * c;
    LL ans = quick(2, c) % MOD;
    cout << ans << endl;
    return 0;
}
