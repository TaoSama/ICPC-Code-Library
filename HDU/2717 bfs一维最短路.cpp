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

int s,g,dp[N],vis[N];
int bfs()
{
	queue<int> q;
	memset(dp,0x3f,sizeof dp); memset(vis,0,sizeof vis);
	dp[s] = 0; q.push(s);
	while(!q.empty()){
		int cur = q.front(),nxt; q.pop();
		nxt = 2*cur;
		if(nxt>=0&&nxt<=200000&&(dp[cur]+1<dp[nxt])){
			dp[nxt] = dp[cur] + 1;
			q.push(nxt);
		}
		for(int i=-1;i<2;++i){
			if(!i) continue;
			nxt = cur+i;
			if(nxt>=0&&nxt<=200000&&(dp[cur]+1<dp[nxt])){
				dp[nxt] = dp[cur] + 1;
				q.push(nxt);
			}
		}
	}
	return dp[g];
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> s>>g) {
		int ans = bfs();
		cout<<ans<<endl;
	}

	return 0;
}
