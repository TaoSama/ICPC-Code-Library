#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool vis[20];

int main() {

    srand(time(0));
    int t = 100;
    cout << t << endl;
    while(t--) {
        int n = 300, m = 300;
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; ++i){
            cout << string((int)1e5 / 300, 'a') << endl;
        }
        cout << endl;
    }
    return 0;
}
