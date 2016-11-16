#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[2][6] = {
    {4, 5, 6, 3, 2, 1},
    {10, 11, 12, 9, 8, 7},
};

typedef unsigned long long ULL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    string s;
    while(cin >> s) {
        ULL n = stoull(s.substr(0, s.size() - 1));
        char c = s.back();
        ULL ans = (n - 1) / 4 * 16, lft = n % 4;

        if(lft == 0) lft = 4;
        int idx1 = lft == 2 || lft == 4;
        int idx2 = c - 'a';
        ans += a[idx1][idx2] + idx1;
        cout << ans << endl;
    }
    return 0;
}
