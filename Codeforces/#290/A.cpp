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

int n, m;

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
//	freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m) {
		string x(m, '#'), s(m - 1, '.');
		string l = "#" + s, r = s + "#";
		bool d = false;
		for(int i = 1; i <= n; ++i)
			if(i & 1) cout << x << endl;
			else if(d) {
				d = !d;
				cout << l << endl;
			} else {
				d = !d;
				cout << r << endl;
			}
	}
	return 0;
}