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

int n; bool ok;
char a[N];
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> (a + 1)) {
		n = strlen(a + 1);
		int low = a[n] - '0'; ok = 0;
		if(low & 1) {
			for(int i = 1; i <= n; ++i) {
				int even = a[i] - '0';
				if(even % 2 == 0 && even < low) {
					swap(a[i], a[n]), ok = 1;
					break;
				}
			}
			if(!ok) {
				for(int i = n; i > 0; --i) {
					int even = a[i] - '0';
					if(even % 2 == 0) {
						swap(a[i], a[n]), ok = 1; break;
					}
				}
			}
		}
		if(ok) cout<<(a+1)<<endl;
		else   cout<<-1<<endl;
	}
	return 0;
}