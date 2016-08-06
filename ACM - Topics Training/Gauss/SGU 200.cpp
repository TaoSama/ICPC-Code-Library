//
//  Created by TaoSama on 2016-07-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int C = 1e5 + 10;

int n, m;

vector<int> prime;
bool vis[C];
void gao() {
    for(int i = 2; i < C; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        if(prime.size() == 100) break;
        for(int j = i + i; j < C; j += i) vis[j] = true;
    }
}

int a[N][N];
int gauss(int n, int m) {
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; continue;}

        swap(a[p], a[r]);
        for(int i = 0; i < n; ++i) {
            if(i != r && a[i][c]) {
                for(int k = c; k <= m; ++k)
                    a[i][k] ^= a[r][k];
            }
        }
    }
    return m - r;
}

typedef long long LL;
struct BigInteger {
    LL x[2];
    static const LL MOD = 1e18;
    BigInteger() {}
    BigInteger(const LL& v) {
        x[0] = v % MOD;
        x[1] = v / MOD;
    }
    BigInteger operator*(int v) {
        BigInteger ret = *this;
        ret.x[1] *= v;
        ret.x[1] += v * ret.x[0] / MOD;
        ret.x[0] = v * ret.x[0] % MOD;
        return ret;
    }
    BigInteger operator--() {
        if(!x[0]) x[0] += MOD, --x[1];
        --x[0];
        return *this;
    }
    void see() {
        if(x[1]) printf("%lld%018lld\n", x[1], x[0]);
        else printf("%lld\n", x[0]);
    }
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    gao();

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        for(int j = 0; j < n; ++j) {
            //number contributes to factor
            while(x % prime[j] == 0) x /= prime[j], a[j][i] ^= 1;
        }
    }

    int freeX = gauss(n, m);
    BigInteger ans(1);
    for(int i = 0; i < freeX; ++i) ans = ans * 2;
    --ans;
    ans.see();

//  BigInteger y((LL)8e18);
//  y.see();
//  y = y * 2;
//  y.see();

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
