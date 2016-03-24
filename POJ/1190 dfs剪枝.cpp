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

int n, v, ans;

void dfs(int c, int r, int h, int lv, int s) {
	if(c > n) {
		if(lv == 0) ans = min(ans, s);
		return;
	}

	if(c > 1 && (s + n - c + 1) >= ans) return;  //当前最小表面积剪枝ans
	if(c > 1 && (r * r * h) * (n - c + 1) < lv) return; //当前最大体积剪枝
	if(n - c + 1 > lv) return;           //当前最小体积剪枝
	for(int i = min(((int)sqrt(lv + 1)), r - 1); i > n - c; --i)
		for(int j = n - c + 1; i * i * j <= lv && j < h; ++j)
			dfs(c + 1, i, j, lv - i * i * j, s + 2 * i * j + (c == 1 ? i*i : 0));
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> v >> n) {
		ans = INF;
		dfs(1, INF, INF, v, 0);
		if(ans == INF) ans = 0;
		cout << ans << endl;
	}

	return 0;
}
