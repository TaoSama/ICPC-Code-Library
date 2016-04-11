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

int n, a[105][105], dp[105];
bool in[105];

int bfs(int s) {
	memset(dp, 0x3f, sizeof dp); memset(in, false, sizeof in);
	queue<int> q; in[s] = true; q.push(s); dp[s] = 0;
	while(!q.empty()) {
		int cur =  q.front(); q.pop();
		for(int nxt = 1; nxt <= n; ++nxt) {
			if(nxt == cur) continue;
			if(dp[nxt] > dp[cur] + a[cur][nxt]) {
				dp[nxt] = dp[cur] + a[cur][nxt];
				if(!in[nxt])
					q.push(nxt), in[nxt] = true;
			}
		}
	}
	int ret = -INF;
	for(int i = 1; i <= n; ++i)
		ret = max(ret, dp[i]);
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n && n) {
		memset(a, 0x3f, sizeof a);
		for(int i = 1; i <= n; ++i) {
			int m; cin >> m;
			while(m--) {
				int j, v; cin >> j >> v;
				a[i][j] = v;
			}
		}

		int id, ans = INF;
		for(int i = 1; i <= n; ++i) {
			int t = bfs(i);
			if(t < ans)
				ans = t, id = i;
		}
		if(ans == INF) cout << "disjoint" << endl;
		else         cout << id << ' ' << ans << endl;
	}

	return 0;
}

//Floyd
/*
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

int n, dp[105][105];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n && n) {
		memset(dp, 0x3f, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			int m; cin >> m;
			while(m--) {
				int j, v; cin >> j >> v;
				dp[i][j] = min(dp[i][j], v);
			}
		}
		for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j) {
					if(dp[i][k] < INF && dp[k][j] < INF &&
					        dp[i][j] > dp[i][k] + dp[k][j])
						dp[i][j] = dp[i][k] + dp[k][j];
				}

		int id, ans = INF;
		for(int i = 1; i <= n; ++i) {
			int t = -INF;
			for(int j = 1; j <= n; ++j)
				if(i != j) t = max(dp[i][j], t);
			if(t < ans)
				ans = t, id = i;
		}
		if(ans == INF) cout << "disjoint" << endl;
		else         cout << id << ' ' << ans << endl;
	}

	return 0;
}
*/
