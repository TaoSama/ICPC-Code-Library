#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x
#define prln(x) cout << #x << " = " << x << endl
const int N = 4000 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], s[N];

vector<int> f[N][N][2];

int dfs(int l, int r, int k, int p) {
    if(r - l + 1 < k) return 0;
    if(f[l][r][p].size() != 100) {
        f[l][r][p] = vector<int>(100, INF + 1);
    }
    int& ret = f[l][r][p][k];
    if(ret != INF + 1) return ret;
    if(p == 0) {
        ret = -INF;
        if(l + k - 1 <= r) {
//            printf("0 choose %d: ret = %d [%d, %d] now = %d\n", k, dfs(l + k, r, k, 1), l, l + k - 1, s[l + k - 1] - s[l - 1]);
            ret = max(ret, dfs(l + k, r, k, 1) + s[l + k - 1] - s[l - 1]);
        }
        if(l + k <= r) {
//            printf("0 choose %d: ret = %d [%d, %d] now = %d\n", k + 1, dfs(l + k + 1, r, k + 1, 1), l, l + k, s[l + k] - s[l - 1]);
            ret = max(ret, dfs(l + k + 1, r, k + 1, 1) + s[l + k] - s[l - 1]);
        }
    } else {
        ret = INF;
        if(l <= r - k + 1) {
//            printf("1 choose %d: ret = %d [%d, %d] now = %d\n", k, dfs(l, r - k, k, 0), r - k + 1, r, s[r] - s[r - k]);
            ret = min(ret, dfs(l, r - k, k, 0) - s[r] + s[r - k]);
        }
        if(l <= r - k) {
//            printf("1 choose %d: ret = %d [%d, %d] now = %d\n", k + 1, dfs(l, r - k - 1, k + 1, 0), r - k, r, s[r] - s[r - k - 1]);
            ret = min(ret, dfs(l, r - k - 1, k + 1, 0) - s[r] + s[r - k - 1]);
        }
    }
//    printf("%d %d %d %d => %d\n", l, r, k, p, ret);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
        printf("%d\n", dfs(1, n, 1, 0));
    }
    return 0;
}
