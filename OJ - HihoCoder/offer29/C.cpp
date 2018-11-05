#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N];
long long f[N][N][2];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    map<int, int> cnt;
    for(int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    memset(f, 0xc0, sizeof f);
    f[0][0][0] = 0;
    for(int i = 0; i < n; ++i) {
        // cout << a[i + 1] << endl;
        for(int j = 0; j <= m; ++j) {
            f[i + 1][j][0] = max(f[i][j][0], f[i][j][1]);
            f[i + 1][j + 1][1] = f[i][j][0] + a[i + 1] * cnt[a[i + 1]];
            if(a[i + 1] - a[i] > 1) {
                f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][1] + a[i + 1] * cnt[a[i + 1]]);
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j < 2; ++j) {
            ans = max(ans, f[n][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
