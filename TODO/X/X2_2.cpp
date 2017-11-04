#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = (1<<17) + 5, mo = 1e9+7, P = 1e9+7;
const double PI = acos(-1.0);
inline ll read(){
	char c=getchar(); ll x=0,f=1;
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}


struct meow{
    double x, y;
    meow(double a=0, double b=0):x(a), y(b){}
};
meow operator +(meow a, meow b) {return meow(a.x+b.x, a.y+b.y);}
meow operator -(meow a, meow b) {return meow(a.x-b.x, a.y-b.y);}
meow operator *(meow a, meow b) {return meow(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);}
meow conj(meow a) {return meow(a.x, -a.y);}
typedef meow cd;

namespace fft {
	int rev[N], maxlen = 1<<17;
	cd omega[N], omegaInv[N];
	void init() {
		for(int i=0; i<maxlen; i++) {
			omega[i] = cd(cos(2*PI/maxlen*i), sin(2*PI/maxlen*i));
			omegaInv[i] = conj(omega[i]);
		}
	}
	void dft(cd *a, int n, int flag) {
		cd *w = flag==1 ? omega : omegaInv;
		for(int i=0; i<n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
		for(int l=2; l<=n; l<<=1) {
			int m = l>>1;
			for(cd *p = a; p != a+n; p += l)
				for(int k=0; k<m; k++) {
					cd t = w[maxlen/l*k] * p[k+m];
					p[k+m] = p[k] - t;
					p[k] = p[k] + t;
				}
		}
		if(flag == -1) for(int i=0; i<n; i++) a[i].x /= n;
	}

	cd a[N], b[N], c[N], d[N]; int z[N];
	void inverse(int *x, int *y, int l) {
		if(l == 1) {y[0] = 1; return;}
		inverse(x, y, (l+1)>>1);
		int n = 1, k = 0; while(n < l<<1) n<<=1, k++;
		for(int i=0; i<n; i++) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(k-1));

		for(int i=0; i<l; i++) a[i] = cd(y[i]>>15), b[i] = cd(y[i]&32767);
		for(int i=l; i<n; i++) a[i] = b[i] = cd();
		dft(a, n, 1); dft(b, n, 1);
		for(int i=0; i<n; i++) {
			cd _a = a[i], _b = b[i];
			a[i] = _a * _a;
			b[i] = _a * _b + _a * _b;
			c[i] = _b * _b;
		}
		dft(a, n, -1); dft(b, n, -1); dft(c, n, -1);
		for(int i=0; i<l; i++)
			z[i] = ( (ll(a[i].x + 0.5) %mo << 30) %mo + (ll(b[i].x + 0.5) %mo << 15) %mo + ll(c[i].x + 0.5) %mo) %mo;

		for(int i=0; i<l; i++)
			a[i] = cd(x[i]>>15), b[i] = cd(x[i]&32767), c[i] = cd(z[i]>>15), d[i] = cd(z[i]&32767);
		for(int i=l; i<n; i++) a[i] = b[i] = c[i] = d[i] = cd();

		dft(a, n, 1); dft(b, n, 1); dft(c, n, 1); dft(d, n, 1);

		for(int i=0; i<n; i++) {
			cd _a = a[i], _b = b[i], _c = c[i], _d = d[i];
			a[i] = _a * _c;
			b[i] = _a * _d + _b * _c;
			c[i] = _b * _d;
		}
		dft(a, n, -1); dft(b, n, -1); dft(c, n, -1);
		for(int i=0; i<l; i++) {
			ll t = ( (ll(a[i].x + 0.5) %mo << 30) %mo + (ll(b[i].x + 0.5) %mo << 15) %mo + ll(c[i].x + 0.5) %mo) %mo;
			y[i] = (y[i] * 2 %mo - t + mo) %mo;
		}
	}
}

int n, m, a[N], b[N];
ll inv[N], fac[N], facInv[N], mi[N];
inline ll C(int n, int m) {return fac[n] * facInv[m] %mo * facInv[n-m] %mo;}
inline ll cal(int n, int m) {
	ll ans = 0;
	mi[0] = 1; for(int i=1; i<=m+1; i++) mi[i] = mi[i-1] * n %mo;
	for(int i=0; i<=m; i++) if(b[i]) (ans += C(m+1, i) * b[i] %mo * mi[m+1-i] %mo) %= mo;
	ans = (ans * inv[m+1]) %mo;
	return ans;
}

int main() {
//	freopen("in", "r", stdin);
	n = 50001;
	inv[1] = fac[0] = facInv[0] = 1;
	for(int i=1; i<=n; i++) {
		if(i != 1) inv[i] = (P - P/i) * inv[P%i] %P;
		fac[i] = fac[i-1] * i %P;
		facInv[i] = facInv[i-1] * inv[i] %P;
	}
	fft::init();
	for(int i=0; i<n; i++) a[i] = facInv[i+1];
	fft::inverse(a, b, n);
	for(int i=0; i<n; i++) b[i] = b[i] * fac[i] %mo;
	for(int i = 0; i <= 10; ++i) printf("%d ", b[i] * (i) % P); puts("");

	int T=read();
	while(T--) {
		n = (read()+1) %mo; m=read();
		printf("%lld\n", cal(n, m));
	}
}
