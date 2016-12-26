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

    int t; cin >> t;
    while(t--) {
        cin.get();
        string s; getline(cin, s);
        char c = s.back();
        if(c == '?') cout << "-_-\n";
        else if(c == '.') cout << "Orz\n";
        else {
            int cnt = 0;
            for(char x : s) if(x == c) ++cnt;
            string ans = "W" + string(cnt, 'o') + "w!";
            cout << ans << '\n';
        }
    }
    return 0;
}
