//
//  Created by TaoSama on 2015-05-04
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

char a[N];
long long nxt[N], ex[N];

void getNxt(char *t) { //t[i...n-1]与t的lcp
    int n = strlen(t); nxt[0] = n;

    int j = 0;
    while(t[j + 1] && t[j + 1] == t[j]) ++j;
    nxt[1] = j;

    int a = 1, p, L;
    for(int i = 2; i < n; ++i) {            //i = k+1
        p = nxt[a] + a - 1, L = nxt[i - a]; //i-a = k+1-a
        if(i - 1 + L < p) nxt[i] = L;       //k+L < p
        else {
            j = max(0, p - i + 1);          //p-k
            while(t[i + j] && t[i + j] == t[j]) ++j; //i+j=k+1+p-k=p+1
            nxt[i] = j;
            a = i;
        }
    }
}

void getEx(char *s, char *t) { //s[i...n-i]与t的lcp
    getNxt(a);
    int n = strlen(s), m = strlen(t);

    int j = 0;
    while(s[j] && t[j] && s[j] == t[j]) ++j;
    ex[0] = j;

    int a = 0, p, L;
    for(int i = 1; i < n; ++i) {
        p = ex[a] + a - 1, L = nxt[i - a];
        if(i - 1 + L < p) ex[i] = L;
        else {
            j = max(0, p - i + 1);
            while(s[i + j] && t[j] && s[i + j] == t[j]) ++j;
            ex[i] = j;
            a = i;
        }
    }
}


struct Matrix {
    int n, m;
    long long mat[2][2];

    Matrix(const int& n = 2, const int& m = 2): n(n), m(m) {}
    Matrix operator* (const Matrix& rhs) {
        Matrix ret(n, rhs.m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < rhs.m; ++j) {
                ret.mat[i][j] = 0;
                for(int k = 0; k < m; ++k) {
                    ret.mat[i][j] = (ret.mat[i][j] +
                                     mat[i][k] * rhs.mat[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (long long k) {
        Matrix ret(n, m), x(n, m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                x.mat[i][j] = mat[i][j];
                if(i == j) ret.mat[i][j] = 1;
                else ret.mat[i][j] = 0;
            }
        }
        while(k) {
            if(k & 1) ret = ret * x;
            x = x * x;
            k >>= 1;
        }
        return ret;
    }
};

long long Fibonacci(long long n) {
    Matrix ret;
    ret.mat[0][0] = 1; ret.mat[0][1] = 1;  // Fn+1 Fn
    ret.mat[1][0] = 1; ret.mat[1][1] = 0;  // Fn   Fn-1
    ret = ret ^ n;
    return ret.mat[0][1];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", a) == 1) {
        getNxt(a);
        int n = strlen(a);
        nxt[n] = 0;
        long long ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            nxt[i] += nxt[i + 1];
            //cout << nxt[i] << ' ' << Fibonacci(nxt[i]) << endl;
            ans += Fibonacci(nxt[i]);
            if(ans >= MOD) ans -= MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
