//
//  Created by TaoSama on 2016-03-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double PI = acos(-1);

typedef complex<double> Complex;

Complex A[N], B[N];
int ans[N];
char s[N >> 2], t[N >> 2];

void rader(Complex *y, int L) {
    for(int i = 1, j = L / 2; i < L - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = L / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex *y, int L, int op) {
    rader(y, L);  //位逆序置换
    for(int h = 2; h <= L; h <<= 1) {
        double ang = op * 2 * PI / h;
        Complex wn(cos(ang), sin(ang)); //n次单位复根
        for(int j = 0; j < L; j += h) {
            Complex w(1, 0); //twiddle factor, initialize to e^0
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t; //butterfly operation
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    //for interpolation
    if(op == -1) for(int i = 0; i < L; i++) y[i] /= L;
}

void convolution(char *s, char *t) {
    int n = strlen(s), m = strlen(t), L;
    for(L = 1; L < n + m; L <<= 1);
    for(int i = 0; i < L; ++i) A[i] = Complex(i < n ? s[n - i - 1] - '0' : 0, 0);
    for(int i = 0; i < L; ++i) B[i] = Complex(i < m ? t[m - i - 1] - '0' : 0, 0);

    fft(A, L, 1); //evaluation
    fft(B, L, 1);
    for(int i = 0; i < L; ++i) A[i] *= B[i];
    fft(A, L, -1); //interpolation

    //calculation
    for(int i = 0; i < L; ++i) ans[i] = A[i].real() + 0.5;
    for(int i = 0; i < L; ++i) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while(--L && ans[L] == 0); //remove extra zeros
    for(int i = L; ~i; --i) putchar(ans[i] + '0'); puts("");
}

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s, t) == 2) {
        convolution(s, t);
    }
    return 0;
}
