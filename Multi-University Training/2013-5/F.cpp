#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        vector<int> v(m, -1);
        v[0] = 0;
        int sum = 0, ans = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            sum = ((sum + x) % m + m) % m;
            if(~v[sum]) ans = max(ans, i - v[sum]);
            else v[sum] = i;
        }
        printf("%d\n", ans);
    }
}
