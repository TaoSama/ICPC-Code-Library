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

int n, a[105][105];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
				cin >> a[i][j], a[i][j] += a[i - 1][j];

		int ans = -INF;
		for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) {
				int sum = 0;
				for(int k = 1; k <= n; ++k) {
					sum += a[j][k] - a[i - 1][k];
					ans = max(sum, ans);
					if(sum < 0) sum = 0;
				}
			}
		cout << ans << endl;

	}


	return 0;
}

