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
const int N = 5e5 + 10;

int n, k, dp[N][30], path[N][30]; //dp[i][j]:前i个结尾是j颜色的结果
char s[N];

int main()
{
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> k >> (s + 1)) {
		for(int i = 1; i <= n; ++i) s[i] -= 'A';
		memset(dp, 0x3f, sizeof dp);
		for(int i = 0; i < k; ++i) dp[1][i] = (s[1] != i);

		for(int i = 2; i <= n; ++i) {
			for(int j = 0; j < k; ++j) {
				for(int x = 0; x < k; ++x)  if(x != j) {
						if(dp[i][j] > dp[i - 1][x]) {
							dp[i][j] = dp[i - 1][x];
							path[i][j] = x;
						}
					}
				dp[i][j] += (s[i] != j);
			}
		}

		int ans = INF, last;
		for(int i = 0; i < k; ++i)
			if(ans > dp[n][i])
				ans = dp[n][i], last = i;

		for(int i = n; i > 0 ; --i)
			s[i] = last + 'A', last = path[i][last];

		cout << ans << '\n' << (s + 1) << endl;
	}
	return 0;
}

