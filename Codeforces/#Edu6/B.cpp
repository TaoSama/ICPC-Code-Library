//
//  Created by TaoSama on 2016-01-21
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

typedef long long LL;
int digit[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a, b;

int gao(int n, int x) {
    int cnt = 0, k;
    for(int i = 1; k = n / i; i *= 10) {
        int high = k / 10;
        if(x == 0) {
            if(high) {
                high--;
            } else {
                break;
            }
        }
        cnt += high * i;
        int cur = k % 10;
        if(cur > x) {
            cnt += i;
        } else if(cur == x) {
            cnt += n - k * i + 1;
        }
    }
    return cnt;
}

int calc(int x) {
    int ret = 0;
    for(int i = 0; i < 10; ++i) ret += gao(x, i) * digit[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &a, &b) == 2) {
        printf("%d\n", calc(b) - calc(a - 1));
    }
    return 0;
}
