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

int n;
short int dp[5005][5005]; //防止MLE  本题还可以用滚动数组求n-(原串和反串的LCS)
char a[5005];

int dfs(int l, int r) {
	if(l >= r) return 0;
	if(dp[l][r] >= 0) return dp[l][r];
	if(a[l] == a[r]) dp[l][r] = dfs(l + 1, r - 1);
	else dp[l][r] = min(dfs(l + 1, r), dfs(l, r - 1)) + 1;
	return dp[l][r];
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> a) {
		memset(dp, -1, sizeof dp);
		int ans = dfs(0, n - 1);
		cout << ans << endl;
	}

	return 0;
}
