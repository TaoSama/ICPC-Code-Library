//
//  Created by TaoSama on 2016-09-10
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

//remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 55;
    LL mat[N][N];
    void init(int r, int c, bool one = false) {
        row = r; col = c;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < row; ++i) mat[i][i] = 1;
    }
    void see() {
        printf("%d %d\n", row, col);
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                printf("%I64d%c", mat[i][j], " \n"[j + 1 == col]);
    }
    Matrix operator+(const Matrix& rhs) {
        Matrix ret = *this;
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if((ret.mat[i][j] += rhs.mat[i][j]) >= MOD)
                    ret.mat[i][j] -= MOD;
        return ret;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < col; ++k) {
            for(int i = 0; i < row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < rhs.col; ++j) {
                    ret.mat[i][j] += mat[i][k] * rhs.mat[k][j] % MOD;
                    ret.mat[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret, x = *this;
        ret.init(row, col, 1);
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x;
            x = x * x;
        }
        return ret;
    }
    Matrix prefix(LL n) {
        Matrix ret, x = *this, t = *this;
        ret.init(row, col);
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x + t;
            t = t * x + t;
            x = x * x;
        }
        return ret;
    }
};

vector<int> primes;
int g[N];
void gao() {
    for(int i = 1; i < N; ++i) g[i] = i;
    for(int i = 2; i < N; ++i) {
        if(g[i] == i) primes.push_back(i);
        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            g[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

vector<pair<int, int> > factorize(int x) {
    vector<pair<int, int> > factors;
    for(int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i) {
        int p = primes[i];
        int e = 0;
        if(x % p == 0) {
            while(x % p == 0) ++e, x /= p;
            factors.push_back({p, e});
        }
        if(x == 1) break;
    }
    if(x > 1) factors.push_back({x, 1});
    return factors;
}

void dfs(int k, int d, vector<pair<int, int> >& factors,
         vector<int>& divisors) {
    if(k == factors.size()) {
        divisors.push_back(d);
        return;
    }

    dfs(k + 1, d, factors, divisors);
    auto& p = factors[k];
    for(int i = 0; i < p.second; ++i) {
        d *= p.first;
        dfs(k + 1, d, factors, divisors);
    }
}

LL n;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int euler(int n, vector<pair<int, int> >& factors) {
    int ret = n;
    for(auto& p : factors) {
        int i = p.first;
        if(n % i == 0) ret = ret / i * (i - 1);
    }
    return ret;
}

Matrix A, B;
LL fib(int x) {
    B = A;
    B = B ^ x;
    return B.mat[1][0];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    A.init(2, 2);
    int a[2][2] = {1, 1, 1, 0};
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            A.mat[i][j] = a[i][j];

    gao();

//    for(int i = 1; i <= 10; ++i)
//        printf("%d = %lld\n", i, fib(i-1)+fib(i+1));
//    puts("");
    int f[10][2][2], g[10][2][2];
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    f[1][0][0] = f[1][1][1] = 1;
    g[1][0][0] = g[1][1][1] = 1;
    for(int i = 2; i < 10; ++i) {
        f[i][0][0] = f[i - 1][0][1] + f[i - 1][0][0];
        f[i][0][1] = f[i - 1][0][0];
        f[i][1][0] = f[i - 1][1][1] + f[i - 1][1][0];
        f[i][1][1] = f[i - 1][1][0];
        g[i][0][0] = f[i - 1][0][0] + f[i - 1][0][1];
        g[i][0][1] = f[i - 1][0][0];
        g[i][1][0] = f[i - 1][1][0] + f[i - 1][1][1];
    }
    for(int i = 1; i < 10; ++i)
        printf("%d = %d\n", i, g[i][0][0] + g[i][0][1] + g[i][1][0]);

    while(cin >> n) {
        if(n == 1) {
            cout << "2\n";
            continue;
        } else {
            vector<pair<int, int> > factors = factorize(n);
            vector<int> divisors;
            dfs(0, 1, factors, divisors);

            LL ans = 0;
            for(auto& div : divisors) {
                ans += euler(n / div, factors) * (fib(div - 1) + fib(div + 1));
                ans %= MOD;
            }
            ans = ans * quick(n, MOD - 2) % MOD;
            cout << ans << endl;
        }
    }

    return 0;
}
