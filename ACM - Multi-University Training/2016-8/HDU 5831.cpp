//
//  Created by TaoSama on 2016-08-12
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, s + 1);
        int l = -1, r = -1;
        for(int i = 1; i <= n; ++i) {
            if(l == -1 && s[i] == ')') l = i;
            if(s[i] == '(') r = i;
        }
//        pr(l); prln(r);
        if(~l && ~r) {
            swap(s[l], s[r]);
            int sum = 0, ok = 1;
            for(int i = 1; i <= n && ok; ++i) {
                sum += s[i] == '(' ? 1 : -1;
                if(sum < 0) ok = false;
            }
            puts(ok && !sum ? "Yes" : "No");
        } else puts("No");
    }

    return 0;
}
