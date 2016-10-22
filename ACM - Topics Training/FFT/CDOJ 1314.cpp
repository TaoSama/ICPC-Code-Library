//
//  Created by TaoSama on 2016-04-20
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
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
#include <complex>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double PI = acos(-1);

typedef complex<double> Complex;

Complex A[1 << 19], B[1 << 19];

void rader(Complex* y, int L) {
    for(int i = 1, j = L / 2; i < L - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = L / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex* y, int L, int op) {
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

typedef long long LL;

int n, m;
LL cnt[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        A[x] += 1;
        B[200000 - x] += 1;
    }

    int L = 1 << 19;
    fft(A, L, 1);
    fft(B, L, 1);
    for(int i = 0; i < L; ++i) A[i] *= B[i];
    fft(A, L, -1);

    for(int i = 0; i <= 2e5; ++i) cnt[i] = A[200000 + i].real() + 0.5;
    cnt[0] = cnt[0] - n >> 1;
//  for(int i = 0; i <= 20; ++i) printf("cnt[%d] = %lld\n", i, cnt[i]);

    pair<LL, int> ans = {(LL)1e18, -1};
    for(int i = 1; i <= m; ++i) {
        LL sum = cnt[0];
        for(int j = i; j <= 2e5; j += i) sum += cnt[j];
        ans = min(ans, {sum, i});
    }
    printf("%d\n", ans.second);
    return 0;
}
