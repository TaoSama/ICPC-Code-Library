#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, a[105], c[105];
bool dp[N];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && (n + m)) {
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) cin >> c[i];

		memset(dp, false, sizeof dp);
		dp[0] = true;

		for(int i = 1; i <= n; ++i) {
			int k = 1;
			while(c[i] > 0) {
				int w = a[i] * min(k, c[i]);
				for(int j = m; j >= w; --j)
					dp[j] |= dp[j - w];
				c[i] -= k; k <<= 1;
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++i) if(dp[i]) ++ans;
		cout << ans << endl;
	}
}

