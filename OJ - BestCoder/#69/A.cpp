//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, a[2];

bool isLeap(int x) {
    return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
}

int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getDay(int y, int m) {
    if(m != 2) return mon[m];
    return mon[m] + isLeap(y);
}

int handle(char *s) {
    bool ret = false;
    bool ok = true;
    for(int i = 7; i < 11; ++i) if(s[i] != s[i + 1]) ok = false; ret |= ok;
    ok = true;
    for(int i = 7; i < 11; ++i) if(s[i] - s[i + 1] != 1) ok = false; ret |= ok;
    ok = true;
    for(int i = 7; i < 11; ++i) if(s[i] - s[i + 1] != -1) ok = false; ret |= ok;

    ok = true;
    int y = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 +
            (s[7] - '0');
    int m = (s[8] - '0') * 10 + (s[9] - '0');
    int d = (s[10] - '0') * 10 + (s[11] - '0');
    if(!(y >= 1980 && y <= 2016 && m >= 1 && m <= 12 && d && d <= getDay(y, m)))
        ok = false; ret |= ok;
    return !ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, a, a + 1);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            char s[15]; scanf("%s", s + 1);
            ans += a[handle(s)];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
