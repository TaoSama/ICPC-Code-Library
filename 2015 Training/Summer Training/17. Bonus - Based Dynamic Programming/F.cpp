//
//  Created by TaoSama on 2015-08-08
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

int n, ans[6000];
int d[] = {2, 3, 5, 7};

void init() {
    set<long long> s; s.insert(1);
    for(int i = 1; i <= 5842; ++i) {
        ans[i] = *s.begin(); s.erase(s.begin());
        for(int j = 0; j < 4; ++j)
            s.insert(1LL * d[j] * ans[i]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(scanf("%d", &n) == 1 && n) {
        printf("The ");
        if(n % 10 == 1 && n % 100 != 11) printf("%dst", n);
        else if(n % 10 == 2 && n % 100 != 12) printf("%dnd", n);
        else if(n % 10 == 3 && n % 100 != 13) printf("%drd", n);
        else printf("%dth", n);
        printf(" humble number is %d.\n", ans[n]);
    }
    return 0;
}
