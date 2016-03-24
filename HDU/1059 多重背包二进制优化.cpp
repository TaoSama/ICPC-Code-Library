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
const int N = 2e5 + 10;

int n, m, ct[10];
bool dp[N];

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	for(int kase = 1;; ++kase) {
		bool ok = false;
		int sum = 0;
		for(int i = 1; i <= 6; ++i)
			cin >> ct[i], sum += ct[i] * i;

		if(!sum) break;

		if(sum & 1) ok = false;
		else {
			sum >>= 1;
			memset(dp, false, sizeof dp);
			dp[0] = true;
			for(int i = 1; i <= 6; ++i) {
				int k = 1;
				while(ct[i] > 0) {
					int w = i * min(ct[i], k);
					for(int j = sum; j >= w; --j)
						if(dp[j - w]) dp[j] = true;
					ct[i] -= k; k <<= 1;
				}
			}
			ok = dp[sum];
		}

		cout << "Collection #" << kase << ":" << endl;
		if(ok)
			cout << "Can be divided.\n" << endl;
		else
			cout << "Can't be divided.\n" << endl;

	}
	return 0;
}