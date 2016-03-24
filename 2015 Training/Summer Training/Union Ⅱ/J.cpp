//
//  Created by TaoSama on 2015-08-24
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

char s[1005];
long long a, b;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%lld%lld", s, &a, &b) == 3) {
        if(a == 9) {puts("A"); continue;}
        if(b == 9) {puts("B"); continue;}

        long long ans = 0, num = 0;
        char last = '+';
        for(int i = 0; s[i]; ++i) {
            if(!isdigit(s[i])) {
                if(last == '+') ans += num;
                else ans -= num;
                last = s[i]; num = 0;
            } else num = num * 10 + s[i] - '0';
        }
        if(last == '+') ans += num;
        else ans -= num;

        if(ans == a) puts("B");
        else puts("A");
    }
    return 0;
}
