#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);

    long long ans = 1LL * n * (n - 1);
    for(int i = 1; i <= n; ++i) { 
        if(a[i] / 8 + 8 > a[i] || a[i] > a[i] * 8 + 8 || a[i] < 88888 && a[i] > 88888) ++ans; 
        int small = lower_bound(a + 1, a + 1 + n, a[i] / 8.0 + 8) - a - 1;
        double to = a[i] * 8.0 + 8;
        if(a[i] < 88888) to = min(to, 88888.0);
        int large = upper_bound(a + 1, a + 1 + n, to) - a;
        // if(large <= small) small = large - 1;
        // cout << small << ' ' << a[small] << ' ' << large << ' ' << a[large] << endl;
        // cout << small + n - large + 1 << endl;
        ans -= small + n - large + 1;
    }
    // for(int i = 1; i <= n; ++i) {
        // for(int j = 1; j <= n; ++j) {
            // if(a[i] / 8 + 8 > a[j] || a[j] > a[i] * 8 + 8 || a[i] < 88888 && a[j] > 88888) {
                // cout << a[i] << ' ' << a[j] << endl;
            // }
        // }
    // }
    cout << ans << endl;
    return 0;
}
