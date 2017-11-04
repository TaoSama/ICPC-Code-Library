#include <bits/stdc++.h>
using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N], cov[26];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        for(int i = 0; i < 26; ++i) cov[i] = i + 'A';
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            char a, b; scanf(" %c %c", &a, &b);
            for(int j = 0; j < 26; ++j)
                if(cov[j] == a) cov[j] = b;
        }
        for(int i = 0; s[i]; ++i) {
            if(isupper(s[i]))
                s[i] = cov[s[i] - 'A'];
            putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
