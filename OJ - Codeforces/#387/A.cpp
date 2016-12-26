#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        int a = 1, b = 1;
        for(int i = 1; i * i <= n; ++i) {
            int j = n / i;
            if(i * j == n) {
                a = i;
                b = j;
            }
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}
