#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL n, m;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &m);
        LL g = __gcd(n, m);

        auto get = [](LL x) {
            LL ret = 1;
            for(LL i = 2; i * i <= x; ++i) {
                if(x % i == 0) {
                    int e = 0;
                    while(x % i == 0) ++e, x /= i;
                    ret *= (e + 1);
                }
                if(x == 1) break;
            }
            if(x > 1) ret *= 2;
            return ret;
        };

        LL up = get(g), dw = get(n) * get(m);
        g = __gcd(up, dw);
        printf("%lld/%lld\n", up / g, dw / g);
    }

    return 0;
}
