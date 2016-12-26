#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int n; char s[300];
    while(cin >> n >> (s + 1)) {
        if(n % 4) {cout << "===" << endl; continue;}
        char sym[] = "AGCT", c[4] = {}, tag = 0;
        for(int i = 1; i <= n; ++i) {
            char *p = strchr(sym, s[i]);
            if(!p) tag++;
            else c[p - sym]++;
        }

        int avg = n / 4;
        bool ok = true;
        for(int i = 0; i < 4 && ok; ++i)
            if(c[i] > avg) ok = false;
        if(!ok) {cout << "===" << endl; continue;}

        for(int i = 1; i <= n; ++i) {
            char *p = strchr(sym, s[i]);
            if(!p) {
                for(int j = 0; j < 4; ++j) {
                    if(c[j] < avg) {
                        ++c[j];
                        s[i] = sym[j];
                        break;
                    }
                }
            }
        }
        cout << (s + 1) << endl;
    }
    return 0;
}
