#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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

int n, m,dp[105][105][2];
bool in[105][105];
int sx, sy, gx, gy, d[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1};
char a[105][105];
struct point {
	int x, y;
	point(int _x, int _y): x(_x), y(_y) {}
};

int bfs() {
	memset(dp, 0x3f, sizeof dp); memset(in,false,sizeof in);
	queue <point> q;
	dp[sx][sy][0] = dp[sx][sy][1] = 1;
	q.push(point(sx, sy)); in[sx][sy] = true;

	while(!q.empty()) {
		point cur = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			point nxt(cur.x + d[i][0], cur.y + d[i][1]);
			if(nxt.x >= 0 && nxt.x <= (n + 1) && nxt.y >= 0 && nxt.y <= (m + 1)
			        && a[nxt.x][nxt.y] != 'X') {
				bool flag = false;
				if(nxt.x == cur.x) {
					if(dp[nxt.x][nxt.y][0] > dp[cur.x][cur.y][0]) {
						flag = true;
						dp[nxt.x][nxt.y][0] = dp[cur.x][cur.y][0];
					}
					if(dp[nxt.x][nxt.y][0] > dp[cur.x][cur.y][1] + 1) {
						flag = true;
						dp[nxt.x][nxt.y][0] = dp[cur.x][cur.y][1] + 1;
					}
				} else {
					if(dp[nxt.x][nxt.y][1] > dp[cur.x][cur.y][1]) {
						flag = true;
						dp[nxt.x][nxt.y][1] = dp[cur.x][cur.y][1];
					}
					if(dp[nxt.x][nxt.y][1] > dp[cur.x][cur.y][0] + 1) {
						flag = true;
						dp[nxt.x][nxt.y][1] = dp[cur.x][cur.y][0] + 1;
					}
				}
				if(flag && !in[nxt.x][nxt.y]) q.push(nxt), in[nxt.x][nxt.y] = true;
				//cout << nxt.x << ' ' << nxt.y;
				//cout << " seg:" << ' ' << dp[nxt.x][nxt.y] << endl;
				//if(nxt.x == gx && nxt.y == gy) return dp[gx][gy];

				//vis[nxt.x][nxt.y] = 1;
				//q.push(nxt);
			}
		}
	}

	return min(dp[gx][gy][0], dp[gx][gy][1]);
}

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int kas = 0;
	while(cin >> m >> n && (m + n)) {
		int seg = 0;
		cout << "Board #" << ++kas << ":" << endl;
		cin.get();
		memset(a, ' ', sizeof a);
		for(int i = 1; i <= n; ++i) cin.getline(a[i]+1,100);
		/*for(int i=0;i<n+2;++i){
			for(int j=0;j<m+2;++j)
				cout<<a[i][j];
			cout<<endl;
		}*/
		while(cin >> sy >> sx >> gy >> gx) {
			if(sx == 0 && sy == 0 && gx == 0 && gy == 0) break;
			a[gx][gy] = ' ';
			int ans = bfs();
			a[gx][gy] = 'X';
			if(ans == INF) cout << "Pair " << ++seg << ": impossible." << endl;
			else		cout << "Pair " << ++seg << ": " << ans << " segments." << endl;
		}
		cout<<endl;
	}
	return 0;
}