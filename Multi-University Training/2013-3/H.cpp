#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[20], tmp[20];
bool isPalindrome[1 << 16];
int f[1 << 16];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 1; i < 1 << n; ++i) {
            int cc = 0;
            for(int j = 0; j < n; ++j)
                if(i >> j & 1) tmp[cc++] = s[j];
            isPalindrome[i] = true;
            for(int j = 0; j < cc >> 1; ++j) {
                if(tmp[j] != tmp[cc - j - 1]) {
                    isPalindrome[i] = false;
                    break;
                }
            }
        }
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int s = 1; s < 1 << n; ++s) {
            for(int s0 = s; s0; s0 = (s0 - 1) & s) {
                if(!isPalindrome[s0]) continue;
                f[s] = min(f[s], f[s ^ s0] + 1);
            }
        }
        printf("%d\n", f[(1 << n) - 1]);
    }
}
