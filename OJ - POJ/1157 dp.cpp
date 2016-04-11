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

int f, v, a[105][105], dp[105][105];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> f >> v) {
		for(int i = 1; i <= f; ++i) for(int j = 1; j <= v; ++j) cin >> a[i][j];

		memset(dp, 0xc0, sizeof dp);

		dp[1][1] = a[1][1];
		for(int i = 2; i <= v; ++i)
			dp[1][i] = max(dp[1][i - 1], a[1][i]);

		for(int i = 2; i <= f; ++i) {
			dp[i][i] = dp[i - 1][i - 1] + a[i][i];
			for(int j = i + 1; j <= v; ++j)
				dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1]);
		}
		cout << dp[f][v] << endl;
	}
	return 0;
}
