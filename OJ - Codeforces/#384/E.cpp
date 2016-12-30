#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
vector<int> wh[N];
int f[N][1 << 8];

int calc(int len) {
    memset(f, 0xc0, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < 1 << 8; ++j) {
            for(int k = 0; k < 8; ++k) {
                if(j >> k & 1) continue;
                int pos = upper_bound(wh[k].begin(), wh[k].end(), i) - wh[k].begin();
                pos += len - 1;
                if(pos >= wh[k].size()) continue;
                f[wh[k][pos]][j | 1 << k] = max(f[wh[k][pos]][j | 1 << k], f[i][j]);
                pos += 1;
                if(pos >= wh[k].size()) continue;
                f[wh[k][pos]][j | 1 << k] = max(f[wh[k][pos]][j | 1 << k], f[i][j] + 1);
            }
        }
    }
    int ans = -INF;
    for(int i = 1; i <= n; ++i) ans = max(ans, f[i][(1 << 8) - 1]);
    if(ans < 0) return -1;
    return ans * (len + 1) + (8 - ans) * len;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        for(int i = 0; i < 8; ++i) wh[i].clear();
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            wh[--a[i]].push_back(i);
        }

        int l = 1, r = n / 8, ans = -1;
        while(l <= r) {
            int m = l + r >> 1;
            int cur = calc(m);
            if(~cur) l = m + 1, ans = cur;
            else r = m - 1;
        }
        if(ans == -1) {
            ans = 0;
            for(int i = 0; i < 8; ++i) ans += !wh[i].empty();
        }
        cout << ans << '\n';
    }
    return 0;
}
