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
const int N = 1e3 + 10;

struct ACM {
	int x, ct, pos;
};
int n, ans;
ACM a[105];
bool check(int x) {
	char s[5], t[5]; bool digit[5];
	sprintf(s, "%d", x);
//	cout << "s: " << s << endl;
	for(int k = 1; k <= n; ++k) {
		memset(t, 0, sizeof t);
		sprintf(t, "%d", a[k].x);
//		cout << a[k].x << ' ' << "t: " << t << endl;
		memset(digit, 0, sizeof digit);
		int ct = 0, pos = 0;

		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				if(s[i] == t[j] && !digit[j]) {
					++ct; digit[j] = true;
					break;
				}
//		cout << "ct: " << ct << endl << endl;
		if(ct != a[k].ct)  return false;
		for(int i = 0; i < 4; ++i)
			if(s[i] == t[i]) ++pos;
//		cout << "pos: " << pos << endl << endl;
		if(pos != a[k].pos) return false;
	}
	return true;
}
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n && n) {
		for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].ct >> a[i].pos;
		int ok = 0;
		for(int i = 1000; i < 10000; ++i)
			if(check(i)) ans = i, ++ok;
		if(ok == 1) cout << ans << endl;
		else      cout << "Not sure" << endl;
	}
	return 0;
}