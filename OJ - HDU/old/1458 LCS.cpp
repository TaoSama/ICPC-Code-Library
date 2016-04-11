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

char s[1005], t[1005];
int dp[1005][1005];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> (s+1) >> (t+1)) {
		memset(dp, 0xc0, sizeof dp);
		int l = strlen(s+1), r = strlen(t+1);
		for(int i=0;i<=r;++i) dp[0][i] = 0;
		for(int i=0;i<=l;++i) dp[i][0] = 0;
		for(int i=1;i<=l;++i) for(int j=1;j<=r;++j){
			if(s[i]==t[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
		cout<<dp[l][r]<<endl;
	}

	return 0;
}
