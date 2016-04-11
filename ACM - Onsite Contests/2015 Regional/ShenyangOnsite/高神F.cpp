#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

#define LL long long

LL a[100010];
vector <int> fac;
int num;
LL sum = 0, m;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int pos, LL _lcm, int sz) {
    if (_lcm >= m) return;
    if (pos == num) {
        if (sz == 0) return ;
        if (sz & 1) {
            LL x = (m - 1) / _lcm;
            sum += x * (2 * _lcm + (x - 1) * _lcm) / 2;
        } else {
            LL x = (m - 1) / _lcm;
            sum -= x * (2 * _lcm + (x - 1) * _lcm) / 2;
        }
        return ;
    }
    if (_lcm % fac[pos] == 0)
        return ;
    dfs(pos + 1, _lcm, sz);
    LL _gcd = gcd(_lcm, fac[pos]);
    _lcm = _lcm / _gcd * fac[pos];
    dfs(pos + 1, _lcm, sz + 1);
}

int main () {
    int t;
    int kase = 0;
//    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%I64d%I64d", &n, &m);
        int ok = 0;
        vector <LL> q;
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            LL _gcd = gcd(a[i], m);

            q.push_back(_gcd);
            if (_gcd == 1)
                ok = 1;
        }
        printf("Case #%d: ", ++kase);
        if (ok) {
            if (m & 1)
                printf("%I64d\n", (LL)(m - 1) / 2 * (m));
            else
                printf("%I64d\n", (LL)(m) / 2 * (m - 1));
            continue;
        }
        sort(q.begin(), q.end());
        num = unique(q.begin(), q.end()) - q.begin();
        fac.clear();
        for (int i = 0; i < num; i++) {
            int ok = 0;
            for (int j = 0; j < fac.size(); j++) {
                if (q[i] % fac[j] == 0)
                    ok = 1;
            }
            if (!ok)
                fac.push_back(q[i]);
        }
        num = fac.size();
        sum = 0;
        dfs(0, 1, 0);
        printf("%I64d\n", sum);
    }
    return 0;
}