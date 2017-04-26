#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char A[N], B[N];
int nxt[N], f[N];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s%s", A, B);
        int n = strlen(A), m = strlen(B);

        nxt[0] = -1;
        for(int i = 0, j = -1; i < m;) {
            if(j == -1 || B[i] == B[j]) nxt[++i] = ++j;
            else j = nxt[j];
        }

        for(int i = 0, j = 0; i < n; ++i) {
            while(~j && A[i] != B[j]) j = nxt[j];
            f[i] = ++j;
        }
        for(int i = 0; i < n; ++i) printf("%d%c", f[i], " \n"[i + 1 == n]);
    }

    return 0;
}
