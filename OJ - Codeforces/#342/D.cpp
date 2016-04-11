//
//  Created by TaoSama on 2016-02-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
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

int n;
char a[N], ans[N];

bool isLeagal(int a, int b) {
    return a >= b && a - b <= 1;
}

bool check(int x, int y) {
	if(!y) return false;
    bool carry = false, ok = true;
    carry = x - y;
    ans[1] = y - y / 2, ans[n] = y / 2;
    for(int i = 2; i <= n / 2; ++i) {
        if(!isLeagal(a[i], a[n - i + 1])) {
            ok = false;
            break;
        }
        int sum = carry * 10 + a[n - i + 1];
//        printf("%d: %d\n", i, sum);
        carry = a[i] - a[n - i + 1];
        ans[i] = sum - sum / 2, ans[n - i + 1] = sum / 2;
    }
    if(n & 1) {
        int sum = carry * 10 + a[n / 2 + 1] - carry;
        if(sum & 1) ok = false;
        ans[n / 2 + 1] = sum / 2;
    }
    return ok;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", a + 1) == 1) {
        n = strlen(a + 1);
        for(int i = 1; i <= n; ++i) a[i] -= '0';
        memset(ans, 0, sizeof ans);
        if(n == 1 && a[1] % 2 == 0) {
            printf("%d\n", a[1] / 2);
            continue;
        }
        if(isLeagal(a[1], a[n]) && check(a[1], a[n])) {
            for(int i = 1; i <= n; ++i) ans[i] += '0';
            puts(ans + 1);
            continue;
        }
        int x = a[1] * 10 + a[2], y = a[n];
        if(isLeagal(x, y)) {
            for(int i = 1; i < n; ++i) a[i] = a[i + 1];
            --n;
            if(check(x, y)) {
                for(int i = 1; i <= n; ++i) ans[i] += '0';
                puts(ans + 1);
                continue;
            }
        }
        puts("0");
    }
    return 0;
}
