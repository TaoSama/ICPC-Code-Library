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

int n, m, a[N], c[N];
int v[N], l[N], r[N];

bool check(int x) {
	memset(c, 0, sizeof c); int sum = 0;
	for(int i = 1; i <= x; ++i)
		c[l[i]] += v[i], c[r[i] + 1] -= v[i];
	for(int i = 1; i <= n; ++i) {
		sum += c[i];
		if(sum>a[i]) return false;
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(0);
	while(scanf("%d%d",&n,&m)!=-1) {
		memset(c, 0, sizeof c);
		for(int i = 1; i <= n; ++i) scanf("%d",a+i);
		for(int i = 1; i <= m; ++i) scanf("%d%d%d",v+i,l+i,r+i);

		int s = 1, g = m, ans = 0;
		while(s <= g) {
			int mid = (s + g) >> 1;
			if(!check(mid)) ans = mid, g = mid - 1;
			else s = mid + 1;
		}
		if(ans) printf("-1\n%d\n",ans);
		else    printf("%d\n",ans);
	}
	return 0;
}
