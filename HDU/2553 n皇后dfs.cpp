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

int n, m, ans, row[15], ret[15];

bool check(int x) {
	for(int i = 1; i < x; ++i) {
		if(row[i] == row[x] || (abs(row[x] - row[i])) == x - i)
			return false;
	}
	return true;
}

void dfs(int i) {
	if(i > n) {++ans; return;}
	for(int j = 1; j <= n; ++j) {
		row[i] = j;
		if(check(i)) {
			dfs(i + 1);
		}
	}
}
void init() {
	for(n = 1; n <= 10; ++n) {
		ans = 0;
		dfs(1);
		ret[n] = ans;
	}
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	init();
	while(cin >> m && m) {

		cout << ret[m] << endl;
	}
	return 0;
}
