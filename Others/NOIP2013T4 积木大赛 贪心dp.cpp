#include <algorithm>
#include <cctype>
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

int n, a[N], dp[N];
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n) {
		/*for(int i=1;i<=n;++i)  cin>>a[i];
		int l=0,r=10000;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid)) r = mid-1;
			else  l = mid+1;
		}*/
		for(int i = 1; i <= n; ++i) cin >> a[i];

		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		for(int i = 1; i <= n; ++i)
			if(a[i] > a[i - 1]) dp[i] = min(dp[i - 1] + a[i] - a[i - 1], dp[i]);
			else dp[i] = dp[i - 1];
		cout << dp[n] << endl;
	}

	return 0;
}
