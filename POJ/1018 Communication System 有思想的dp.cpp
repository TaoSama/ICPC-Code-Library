#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

int t, n, dp[105][10005];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	cin >> t;
	while(t--) {
		cin >> n;
		memset(dp, 0x3f, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			int m, b, p; cin >> m;
			while(m--) {
				cin >> b >> p;
				if(i == 1) dp[1][b] = p;
				else {
					for(int k = 0; k < 10005; ++k)
						if(b <= k) dp[i][b] = min(dp[i][b], dp[i - 1][k] + p);
						else       dp[i][k] = min(dp[i][k], dp[i - 1][k] + p);
				}
			}
		}
		double ans = 0;
		for(int i = 0; i < 10005; ++i)
			ans = max(ans, i / (double)dp[n][i]);
		cout << fixed << setprecision(3) << ans << endl;

	}

	return 0;
}