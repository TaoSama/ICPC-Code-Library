#include <algorithm>
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;

int n;
struct BigInteger {
	int digits[1010];
	BigInteger() {memset(digits, 0, sizeof digits);}
	BigInteger(const string& s) {
		for(int i = s.size() - 1, t = 1; i >= 0; --i, ++t)
			digits[N - t] = s[i] - '0';
	}
	BigInteger operator+(const BigInteger& b) {
		BigInteger ret;
		for(int i = N - 1; i >= 0; --i) {
			if(ret.digits[i] + digits[i] + b.digits[i] > 9)
				ret.digits[i] = ret.digits[i] + digits[i] + b.digits[i] - 10,
				                ++ret.digits[i - 1];
			else
				ret.digits[i] += digits[i] + b.digits[i];
		}
		return ret;
	}
	friend istream& operator>>(istream& in, BigInteger& b) {
		string s; in >> s;
		for(int i = s.size() - 1, t = 1; i >= 0; --i, ++t)
			b.digits[N - t] = s[i] - '0';
		return in;
	}
	friend ostream& operator<<(ostream& os, const BigInteger& b) {
		bool firstZero = true;
		for(int i = 0; i < N; ++i) {
			if(b.digits[i] || !firstZero) {
				os << b.digits[i];
				firstZero = false;
			}
		}
		if(firstZero) os << 0;
		return os;
	}
};
int main() {
#ifdef LOCAL
	freopen("ACM_in.txt", "r", stdin);
	//freopen("ACM_out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int kase = 1; kase <= n; ++kase) {
			BigInteger a, b;
			cin >> a >> b;
			//cout << a << endl;
			//cout << b << endl;
			//cout << a + b << endl;
			if(kase > 1) cout << endl;
			cout << "Case " << kase << ":" << endl;
			cout << a << " + " << b << " = " << a + b << endl;
		}
	}
	return 0;
}