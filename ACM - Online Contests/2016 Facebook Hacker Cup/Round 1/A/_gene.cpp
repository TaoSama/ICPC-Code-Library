#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool vis[20];

int main() {

    srand(time(0));
    int t = 10;
    cout << t << endl;
    while(t--) {
        int n = 1000;
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            int x = rand() % 10 + 1;
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
