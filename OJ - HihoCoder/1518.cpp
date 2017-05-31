#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], vis[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(vis[a[i]]) continue;
        int t = a[i], cnt = 0;
        while(!vis[t]) {
            ++cnt;
            vis[t] = true;
            t = a[t];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
