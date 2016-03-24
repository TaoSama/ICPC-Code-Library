//
//  Created by TaoSama on 2015-08-15
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n;

long long __lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int getlen(long long x) {
    char buf[50]; sprintf(buf, "%lld", x);
    return strlen(buf);
}

void print(long long &up, long long &down) {
    long long val = up / down;
    up %= down;
    if(up == 0) {printf("%lld\n", val); return;}

    long long gcd = __gcd(up, down);
    up /= gcd; down /= gcd;

    int a = getlen(val), b = getlen(down);
    for(int i = 1; i <= a + 1; ++i) putchar(' ');
    printf("%lld\n%lld ", up, val);
    for(int i = 1; i <= b; ++i) putchar('-');
    puts("");
    for(int i = 1; i <= a + 1; ++i) putchar(' ');
    printf("%lld\n", down);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        long long up = 1, down = 1;
        for(int i = 2; i <= n; ++i) {
            long long lcm = __lcm(down, i);
            up = up * (lcm / down) + lcm / i;
            long long gcd = __gcd(up, lcm);
            up /= gcd; down = lcm / gcd;
        }
        up *= n;
        print(up, down);
    }
    return 0;
}
