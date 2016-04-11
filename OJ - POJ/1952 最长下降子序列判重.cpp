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

int n, a[5005], dp[5005], cnt[5005];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) dp[i] = 0, cnt[i] = 0;
		a[0] = INF; dp[0] = 0; cnt[0] = 1;

		for(int i = 1; i <= n; ++i) {
			int Max = 0, ct = 0;
			for(int j = 0; j < i; ++j) {
				if(a[i] < a[j]) Max = max(Max, dp[j]);
				else if(a[i] == a[j]) cnt[j] = 0;
			}
			for(int j = 0; j < i; ++j)
				if(a[i] < a[j] && dp[j] == Max) ct += cnt[j];
			dp[i] = Max + 1;
			cnt[i] = ct;
		}
		int ans = 0, anst = 0;
		for(int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
		for(int i = 1; i <= n; ++i) if(dp[i] == ans) anst += cnt[i];

		cout << ans << ' ' << anst << endl;
	}

	return 0;
}
