//
//  Created by TaoSama on 2015-05-06
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string s;
long long n, m;

long long tenpow(int x){
	long long ret = 1;
	for(int i = 1; i <= x; ++i)
		ret *= 10;
	return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s;
        int p = s.find('.');
        n = atoll(s.substr(0, p).c_str());
        m = atoll(s.substr(p + 1, s.size() - p + 1).c_str());

        long long ten = tenpow(s.size() - p - 1);
        int gcd = __gcd(m, ten);
        n = n * ten / gcd + m / gcd;
        m = ten / gcd;
        cout << n << '/' << m << '\n';
    }
    return 0;
}
