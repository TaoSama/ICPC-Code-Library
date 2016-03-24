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
const int N = 1e6 + 10;

int n, m, k, a[1005][1005];
bool isLegal(int x, int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m >> k) {
		memset(a, 0, sizeof a);
		int ans = 0 , ok = 0;
		for(int i = 1; i <= k; ++i) {
			int x, y; cin >> x >> y;
			a[x][y] = 1;
			if(!ok) {
				if(isLegal(x - 1, y) && isLegal(x - 1, y - 1) && isLegal(x, y - 1)
				        && a[x - 1][y] && a[x - 1][y - 1] && a[x][y - 1])
					ok = 1, ans = i;
				if(isLegal(x, y - 1) && isLegal(x + 1, y - 1) && isLegal(x + 1, y)
				        && a[x][y - 1] && a[x + 1][y - 1] && a[x + 1][y])
					ok = 1, ans = i;
				if(isLegal(x - 1, y) && isLegal(x - 1, y + 1) && isLegal(x, y + 1)
				        && a[x - 1][y] && a[x - 1][y + 1] && a[x][y + 1])
					ok = 1, ans = i;
				if(isLegal(x + 1, y) && isLegal(x + 1, y + 1) && isLegal(x, y + 1)
				        && a[x + 1][y] && a[x + 1][y + 1] && a[x][y + 1])
					ok = 1, ans = i;
			}
		}
		if(ok) cout << ans << endl;
		else   cout << 0 << endl;
	}
	return 0;
}