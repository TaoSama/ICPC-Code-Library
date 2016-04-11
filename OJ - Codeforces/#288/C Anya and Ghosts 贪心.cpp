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

int m, t, r, w[305], ct[1005];
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> m >> t >> r) {
		CLR(ct);
		for(int i = 1; i <= m; ++i) cin >> w[i], w[i] += 305;
		for(int i = 1; i <= m; ++i) {
			int cnt = 0;
			for(int j = w[i] - t; j < w[i]; ++j) cnt += ct[j];
			for(int j = w[i] - 1; j >= w[i] - t && cnt < r; --j) {
				if(ct[j]) continue;
				ct[j] = 1; ++cnt;
			}
			if(cnt != r) {
				cout << -1 << endl;
				return 0;
			}
		}

		cout << count(ct + 1, ct + 1005, 1) << endl;
	}
	return 0;
}
