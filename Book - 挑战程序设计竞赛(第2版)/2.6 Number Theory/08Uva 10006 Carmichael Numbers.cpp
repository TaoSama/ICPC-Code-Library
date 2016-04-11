//
//  Uva 10006 Carmichael Numbers
//
//  Created by TaoSama on 2015-03-24
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long n;
long long ksm(long long x, long long n, long long m) {
    long long ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

bool is_prime(int n) {
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

bool check(long long n) {
    if(is_prime(n)) return false;
    else {
        for(int i = 2; i < n; ++i) {
            if(ksm(i, n, n) != i) return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        if(check(n))
            cout << "The number " << n << " is a Carmichael number." << endl;
        else cout << n << " is normal." << endl;
    }
    return 0;
}
