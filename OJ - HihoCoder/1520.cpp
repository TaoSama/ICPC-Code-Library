#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, x, y;
char s[N];
bool f1[205][N];

int main() {

    scanf("%s", s + 1);
    int n = strlen(s + 1);
    scanf("%d%d", &x, &y);
    if(n == 1 && s[1] == '?' && y == 0) {
        puts("0");
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < x; ++j) {
            f1[i][j] = 0;
        }
    }
    f1[n][y] = 1;
    for(int i = n; i; --i) {
        for(int j = 0; j < x; ++j) {
            if(s[i] == '?') {
                for(int k = 0; k < 10; ++k) {
                    if(i == 1 && k == 0) continue;
                    int nj = (j * 10 + k) % x;
                    if(f1[i][nj]) {
                        f1[i - 1][j] = 1;
//                        printf("%d %d + %d->%d\n", i, j, k, nj);
                    }
                }
            } else {
                int k = s[i] - '0';
                int nj = (j * 10 + k) % x;
                if(f1[i][nj]) {
                    f1[i - 1][j] = 1;
//                    printf("%d %d + %d->%d\n", i, j, k, nj);
                }
            }
        }
    }



//  prln(f1[1][0]);
    if(f1[0][0] == 0) {
        puts("No solution");
    } else {
        string ans;
        for(int i = 0, j = 0; i < n; ++i) {
            if(s[i + 1] == '?') {
                for(int k = 0; k < 10; ++k) {
                    if(i == 0 && k == 0) continue;
                    int nj = (j * 10 + k) % x;
                    if(f1[i + 1][nj]) {
                        ans += char('0' + k);
                        j = nj;
                        break;
                    }
                }
            } else {
                int k = s[i + 1] - '0';
                ans += s[i + 1];
                int nj = (j * 10 + k) % x;
                assert(f1[i + 1][nj]);
                j = nj;
            }
        }
        puts(ans.c_str());
    }

    return 0;
}
