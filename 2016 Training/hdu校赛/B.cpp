#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int digit[N], f[N][N];

int dfs(int i, int s, int e) {
    if(!i) return 1;
    if(!e && ~f[i][s]) return f[i][s];
    int to = e ? digit[i] : 9;
    int ret = 0;
    for(int d = s; d <= to; ++d) {
        ret += dfs(i - 1, d, e && d == to);
    }
    return e ? ret : f[i][s] = ret;
}

int calc(int x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    memset(f, -1, sizeof f);
    prln(calc((int)1e9));
    while(t--) {
        int x; scanf("%d", &x);
        printf("%d\n", calc(x) - 1);
    }
    return 0;
}
