#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int last[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    while(scanf("%d%s", &n, s + 1) == 2) {
        int ans = 0;
        int last = 0;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == '>') last = 1;
            if(s[i] == '<') ans += !last;
        }
        last = 0;
        for(int i = n; i; i--) {
            if(s[i] == '<') last = 1;
            if(s[i] == '>') ans += !last;
        }
        printf("%d\n", ans);
    }
    return 0;
}
