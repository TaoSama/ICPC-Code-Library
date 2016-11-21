#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, s;
int cnt[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d%d", &n, &s) == 2) {
        int ans = 0;
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(i == s) {
                ans += x != 0;
                x = 0;
            } else {
                if(x == 0) x = n;
            }
            ++cnt[x];
        }

        int maxv = -1;
        for(int i = n; i && maxv == -1; --i) if(cnt[i]) maxv = i;

        for(int i = 1; i < n; ++i) {
            if(i >= maxv) break;
            if(!cnt[i]) {
                ++ans;
                --cnt[maxv];
                while(cnt[maxv] == 0) --maxv;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
