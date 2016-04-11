#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p, a[N];

int main() {
//    freopen("in.txt", "r", stdin);
    int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &p);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        long long ans = 0;
        for(int l = 1; l <= n; ++l){
            for(int r = l; r <= n; ++r){
                int sum = 0;
                for(int i = l; i <= r; ++i){
                    sum += a[i];
                    if(sum > p) break;
                }
                ans += sum <= p;
            }
        }

        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans);
	}
    return 0;
}
