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

int n, m, ans;
char a[105][105];
int d[4][2] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
	a[x][y] = '*';
	for(int i = -1; i < 2; ++i) {
		for(int j = -1; j < 2; ++j) {
			int nx = x + i, ny = y + j;
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '@')
				dfs(nx, ny);
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && n) {
		ans = 0;
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];

		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
				if(a[i][j] == '@') dfs(i, j), ++ans;
		cout << ans << endl;

	}

	return 0;
}