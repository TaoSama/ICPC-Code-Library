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

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        map<int, int> mp;
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(mp[x] == 1) ans.push_back(x);
            ++mp[x];
        }
        sort(ans.begin(), ans.end());
        if(!ans.size()) puts("none");
        else {
            for(int i = 0; i < ans.size(); ++i)
                printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
        }
    }
    return 0;
}
