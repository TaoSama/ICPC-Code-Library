#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + 2 * n);
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += a[n + n - i + 1] - a[i];
        printf("%d\n", ans);
    }
    return 0;
}
