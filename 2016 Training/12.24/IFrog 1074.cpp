#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
bool vis[N][N];
int f[N][N];

int dfs(int l, int r) {
    if(l > r) return 0;
    int& ret = f[l][r];
    if(vis[l][r]) return ret;
    ret = -INF;
    for(int k = l; k <= r; ++k) {
        int cost = a[l - 1] * a[r + 1] * a[k];
        ret = max(ret, dfs(l, k - 1) + dfs(k + 1, r) + cost);
    }
    vis[l][r] = true;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        a[0] = a[n + 1] = 1;
        memset(vis, 0, sizeof vis);
        printf("%d\n", dfs(1, n));
    }
    return 0;
}
