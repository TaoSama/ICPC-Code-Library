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

long long  n, a[N], dp[N];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int kase = 0, x;
	while(cin >> x) {
		if(x == -1) {
			if(n == 0) continue;
			for(int i = 1; i <= n; ++i) dp[i] = 1;
			long long ans = 1;
			for(int i = 2; i <= n; ++i) {
				for(int j = 1; j < i; ++j) {
					if(a[i] <= a[j]) dp[i] = max(dp[i], dp[j] + 1);
				}
				//cout << dp[i] << ' ';
				ans = max(ans, dp[i]);
			}
			//cout <<dp[1]<< endl;
			cout << "Test #" << ++kase << ":" << endl;
			cout << "  maximum possible interceptions: " << ans << '\n' << endl;
			n = 0; continue;
		}
		a[++n] = x;
	}

	return 0;
}
