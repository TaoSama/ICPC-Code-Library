
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

int n, a[15], ret[1005], path[1005][15][15];
bool dp[1005][15][15];  //前i个数 第j个数 差值k
//dp[i][j][k] dp[i-1][j*][k*] j-k*=k ==> k*=j-k

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	for(int i = 1; i <= 10; ++i) scanf("%1d", a + i);
	scanf("%d",&n);  //cin不能与scanf混用 同理另一个

	for(int i = 1; i <= 10; ++i) if(a[i]) dp[1][i][i] = true;

	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= 10; ++j) if(a[j]) {
				for(int k = 1; k < j; ++k)
					for(int x = 1; x <= 10; ++x) if(a[x] && x != j) {
							if(dp[i - 1][x][j - k]) {
								dp[i][j][k] = true;
								path[i][j][k] = x;
							}
						}
			}
	}

	int ans = 0, l, r;
	for(int i = 1; i <= 10; ++i) for(int j = 1; j <= 10; ++j) {
			if(dp[n][i][j])
				ans = 1, l = i, r = j;
		}

	if(ans) {
		cout << "YES" << endl;
		for(int i = n; i > 0; --i) {
			ret[i] = l;
			int tl = l, tr = r;
			r = tl - tr;
			l = path[i][tl][tr];
		}
		cout << ret[1];
		for(int i = 2; i <= n; ++i) cout << ' ' << ret[i]; cout << endl;
	} else cout << "NO" << endl;

	return 0;
}
