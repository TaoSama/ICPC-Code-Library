
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double PI = acos(-1);

int n, x, a[N];
int cnt[N];
typedef complex<double> Complex;
void rader(Complex* y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex* y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        double ang = op * 2 * PI / h;
        Complex wn(cos(ang), sin(ang));
        for(int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(op == -1) for(int i = 0; i < len; i++) y[i] /= len;
}
Complex A[N << 2], B[N << 2];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> x) {
        for(int i = 0; i <= n; ++i) cnt[i] = 0;
        cnt[0] = 1;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] = a[i] < x;
            a[i] += a[i - 1];
            ++cnt[a[i]];
        }
        int len = 1;
        while(len <= n * 2 + 2) len <<= 1;
        for(int i = 0; i < len; ++i) {
            A[i] = Complex(i <= n ? cnt[i] : 0, 0);
            B[i] = Complex(i <= n ? cnt[n - i] : 0, 0);
        }
        fft(A, len, 1);
        fft(B, len, 1);
        for(int i = 0; i < len; i++) A[i] *= B[i];
        fft(A, len, -1);
        
        long long zero = 0;
        for(int i = 0; i <= n; ++i) {
            zero += 1ll * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << zero << ' ';
        for(int i = 1; i <= n; ++i) {
            long long x = A[n - i].real() + 0.5;
            cout << x << " \n"[i == n];
        }
    }
    return 0;
}
