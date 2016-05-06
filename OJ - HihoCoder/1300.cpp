//
//  Created by TaoSama on 2016-05-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];
long long f[N];
int num[N];
int l[N], stk[N], top;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') stk[++top] = i;
        else if(top) l[i] = stk[top--];
    }
    for(int i = 1; i <= n; ++i) {
        f[i] += f[i - 1];
        if(s[i] == ')' && l[i]) {
            num[i] = num[l[i] - 1] + 1;
            f[i] += num[i];
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}
