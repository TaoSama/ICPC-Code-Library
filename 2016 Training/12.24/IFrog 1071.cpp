#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
LL a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            a[i] += a[i - 1];
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", b + i);
            b[i] += b[i - 1];
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        bool ok = true;
        for(int i = 1; i <= n; ++i) ok &= a[i] == b[i];
        puts(ok ? "Yes" : "No");
    }
    return 0;
}
