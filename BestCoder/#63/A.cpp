//
//  Created by TaoSama on 2015-11-21
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

typedef long long LL;

int n, m, a[105];

struct BigInterger {
    vector<int> digit;
    BigInterger(int x = 0) {
        for(; x; x /= 10) digit.push_back(x % 10);
    }
    BigInterger operator+ (const BigInterger& b) const {
        BigInterger ret; ret.digit.clear();
        for(int i = 0, carry = 0; ; ++i) {
            if(carry == 0 && i >= digit.size() && i >= b.digit.size()) break;
            int tmp = carry;
            if(i < digit.size()) tmp += digit[i];
            if(i < b.digit.size()) tmp += b.digit[i];
            ret.digit.push_back(tmp % 10);
            carry = tmp / 10;
        }
        return ret;
    }
    void print() {
        for(int i = digit.size() - 1; ~i; --i) printf("%d", digit[i]);
        if(digit.size()) puts("");
        else puts("0");
    }
} dp[105][105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) dp[i][1] = BigInterger(1);
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= m && j <= i; ++j) {
                for(int k = 1; k < i; ++k) {
                    if(a[i] > a[k])
                        dp[i][j] = dp[i][j] + dp[k][j - 1];
                }
            }
        }
        BigInterger ans;
        for(int i = 1; i <= n; ++i) ans = ans + dp[i][m];
        ans.print();
    }
    return 0;
}
