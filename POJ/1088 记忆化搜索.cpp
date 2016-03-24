#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int n, m, step, a[105][105], vis[105][105], ret[105][105];
int d[4][2] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y) {
	if(ret[x][y]) return ret[x][y];
	ret[x][y] = 1;
	for(int i = 0; i < 4; ++i) {
		int nx = x + d[i][0], ny = y + d[i][1];
		if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && (a[nx][ny] < a[x][y])) {
			ret[x][y] = max(ret[x][y], dfs(nx, ny) + 1);
		}
	}
	return ret[x][y];
}

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];

		CLR(vis); CLR(ret);

		int ans = -INF;
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
				ans = max(ans, dfs(i, j));
		cout << ans << endl;

	}

	return 0;
}
