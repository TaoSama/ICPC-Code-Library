#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        n -= m;
        int ans = INF;
        int a[] = {10, 6, 3}, b[] = {4, 3, 2};
        for(int i = 0; i < 3; ++i) {
            int tn = n, tm = m, tmp = 0;
            for(int j = 0; j < i; ++j) {
                int cnt = tn / a[j];
                tmp += cnt * b[j];
                tn -= cnt * a[j];
            }
            int cnt = (tn + a[i] - 1) / a[i];
//            pr(i); prln(cnt);
            tmp += cnt * b[i];
            tn -= cnt * a[i];
            tm += tn;
            if(tm < 0) tm = 0;
            tmp += (tm + 2) / 3;
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
