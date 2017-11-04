#include <cstdio>

using namespace std;

int arr[1001][1001];
int tmp[1001][1001];

int main() {
	freopen("CountingStar.in","r",stdin);
	freopen("out","w",stdout);
	int T;
	scanf("%d", &T);
	
	for (int i = 1; i <= T; ++i) {
		int n;
		scanf("%d", &n);
		for (int j = n; j >= 1; --j) {
			int v = 0;
			for (int k = 1; k <= n; ++k) {
				scanf("%d", &arr[j][k]);
			}
		}
		for (int j = 2; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				arr[j][k] += arr[j-1][k];
				//printf("%d\t", arr[j][k]);
			}
			//printf("\n");
		}
		printf("Case #%d:\n", i);
		int m;
		scanf("%d", &m);
		for (int j = 1; j <= m; ++j) {
			int x, y;
			scanf("%d %d", &x, &y);
			long long int ret = 0;
			for (int k = 1; k <= x; ++k) {
				int z = (double)y/x * k;
				ret += arr[z][k];
			}
			printf("%lld\n", ret);
		}
	}
	return 0;
}
