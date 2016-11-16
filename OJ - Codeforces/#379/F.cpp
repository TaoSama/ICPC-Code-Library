#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

//a+b=(a|b)+(a&b)
//a+b=(a^b)+(a&b)*2
//a|b=(a^b)+(a&b)

int n;
int a[N], b[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(scanf("%d", &n) == 1) {
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", b + i);
            sum += b[i];
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", c + i);
            sum += c[i];
        }

        if(sum % (2 * n)) {puts("-1"); continue;}
        sum /= 2 * n;

        bool ok = true;
        vector<int> ones(30, 0);
        for(int i = 1; i <= n && ok; ++i) {
            int t = b[i] + c[i] - sum;
            if(t % n) ok = false;
            a[i] = t / n;
            for(int j = 0; j < 30; ++j) ones[j] += a[i] >> j & 1;
        }

        for(int i = 1; i <= n && ok; ++i) {
            LL tb = 0, tc = 0;
            for(int j = 0; j < 30; ++j) {
                if(a[i] >> j & 1) {
                    tb += (LL)ones[j] << j;
                    tc += (LL)n << j;
                } else {
                    tc += (LL)ones[j] << j;
                }
            }
            if(tb != b[i] || tc != c[i]) ok = false;
        }

        if(!ok) {puts("-1"); continue;}

        for(int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);

    }
    return 0;
}