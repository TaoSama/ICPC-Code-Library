//
//  Created by TaoSama on 2015-12-04
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

char s[25];
int n, l;

int calc1() {
    int ret = 0;
    char last = '+';
    for(int i = 0; i < l; i += 2) {
        int d = s[i] - '0';
        if(last == '+') ret += d;
        else ret *= d;
        last = s[i + 1];
    }
    return ret;
}

int calc2() {
    int ret = 0, mul = 1;
    char last = '*';
    for(int i = 0; i < l; i += 2) {
        int d = s[i] - '0';
        if(last == '+') ret += mul, mul = d;
        else mul *= d;
        last = s[i + 1];
    }
    ret += mul;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%d", s, &n) == 2) {
        l = strlen(s);
        int ans1 = calc1(), ans2 = calc2();
        if(ans1 == n && ans2 == n) puts("U");
        else if(ans1 != n && ans2 != n) puts("I");
        else if(ans1 == n) puts("L");
        else puts("M");
    }
    return 0;
}
