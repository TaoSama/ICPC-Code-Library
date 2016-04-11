#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool vis[20];

int main() {

    srand(time(0));
    int t = 5;
    cout << t << endl;
    while(t--) {
        int n = rand() % 10 + 1, m = rand() % (2 * n) + 1;
        cout << n << endl;
        char a[2][25]; memset(a, 'X', sizeof a); a[0][n] = a[1][n] = 0;
        set<pair<int, int> > s;
        while(m--) {
            int x, y;
            do {
                x = rand() % 2, y = rand() % n;
            } while(s.count({x, y}));
            a[x][y] = '.';
        }
        cout << a[0] << endl << a[1] << endl;
    }
    return 0;
}
