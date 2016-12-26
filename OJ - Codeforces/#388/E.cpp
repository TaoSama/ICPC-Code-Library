#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

typedef long long LL;
struct BIT {
    int n;
    LL b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    LL sum(int i) {
        LL ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit, cnt;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);

    bit.init(n);
    cnt.init(n);
    double ans = 0, tot = 1. * n * (n + 1) / 2;
    for(int i = 1; i <= n; ++i) {
        double small = bit.sum(a[i]);
        double large = bit.sum(n) - small;
        double largeOnes = cnt.sum(n) - cnt.sum(a[i]);
        small *= n - i + 1;
        large *= n - i + 1;
        ans += (largeOnes - large / tot) + 0.5 * large / tot;
        ans += 0.5 * small / tot;
        bit.add(a[i], i);
        cnt.add(a[i], 1);
    }
    printf("%.12f\n", ans);


//    {
//        double ans = 0, tot = 1. * n * (n + 1) / 2;
//        for(int i = 1; i <= n; ++i) {
//            for(int j = 1; j < i; ++j) {
//                double choose = 1. * j * (n - i + 1);
//                if(a[j] > a[i]) {
//                    ans += (1 - 1. * choose / tot) + 0.5 * choose / tot;
//                } else {
//                    ans += 0.5 * choose / tot;
//                }
//            }
//        }
//        printf("%.12f\n", ans);
//    }

    return 0;
}
