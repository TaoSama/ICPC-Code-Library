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
const int N = 1e5 + 10;

int n, m, vis[55][55];
char a[55][55];
bool ok; int d[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1};

void dfs(int s, int g, int i, int j, char c, int ct) {
	if(ok) return;
	if(((abs(s - i) == 1 && g - j == 0) || (abs(g - j) == 1
	                                        && s - i == 0)) && ct >= 4) {
		//cout << "ct:" << ct << endl;
		ok = true;
		return;
	}
	for(int k = 0; k < 4; ++k) {
		int x = i + d[k][0], y = j + d[k][1];
		if(!vis[x][y] && a[x][y] == c && x >= 1 && x <= n && y >= 1
		        && y <= m) {
			vis[x][y] = 1;
			dfs(s, g, x, y, a[x][y], ct + 1);
			vis[x][y] = 0;
		}

	}
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
//	freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m) {
		ok = false; CLR(vis);
		for(int i = 1; i <= n; ++i) cin >> &a[i][1];
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				vis[i][j] = 1;
				dfs(i, j, i, j, a[i][j], 1);
				vis[i][j] = 0;
				if(ok) break;
			}
			if(ok) break;
		}
		if(ok) cout << "Yes" << endl;
		else   cout << "No" << endl;
	}
	return 0;
}