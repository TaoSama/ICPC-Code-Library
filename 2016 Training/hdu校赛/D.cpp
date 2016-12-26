#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N];
int cost[] = {4, 2, 2, 4};
int damage[] = {2, 1, 3, 6};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            string s; cin >> s;
            if(s == "Fire") a[i] = 3;
            else if(s == "Ice") a[i] = 2;
            else if(s == "Dog") a[i] = 1;
            else a[i] = 0;
        }
        sort(a, a + n);

        bool ok = false;
        for(int s = 0; s < 1 << n && !ok; ++s) {
            int buf = 0, atk = 0, tot = 0;
            for(int i = 0; i < n; ++i) {
                if(s >> i & 1) {
                    if(a[i] < 2) buf += damage[a[i]];
                    else atk += buf + damage[a[i]];
                    tot += cost[a[i]];
                }
            }
            if(tot <= 10 && atk >= m) ok = true;
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
