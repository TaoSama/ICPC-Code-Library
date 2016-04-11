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

int m, n, ans, dp[15][15];

void dfs(int p, int last, int left) {
	if(p > n) {
		if(left == 0) ++ans;
		return;
	}
	for(int i = 0; i <= last; ++i) {
		if((p - n + 1)*i > left) continue;
		dfs(p + 1, i, left - i);
	}
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	int t; cin >> t;

	/*CLR(dp);         //dp“≤ø…“‘
	for(int i=0;i<11;++i) dp[1][i] = 1;
	for(int i=2;i<11;++i) for(int j=0;j<11;++j){
		dp[i][j] = dp[i-1][j];
		if(j>=i) dp[i][j]+=dp[i][j-i];

	}*/

	while(t--) {
		cin >> m >> n;
		ans = 0;
		dfs(1, m, m);
		cout << ans << endl;
	}

	return 0;
}
