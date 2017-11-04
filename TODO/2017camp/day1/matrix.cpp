//
//  Created by TaoSama on 2017-02-13
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    //  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int n = 1; n <= 5; ++n) {
        if(n == 1) printf("if(n==%d){\n", n);
        else printf("else if(n==%d){\n", n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("ret[%d][%d]=(", i, j);
                for(int k = 0; k < n; ++k) {
                    if(k) printf("+1LL*a[%d][%d]*m[%d][%d]", i, k, k, j);
                    else printf("1LL*a[%d][%d]*m[%d][%d]", i, k, k, j);
                }
                puts(")%mod;");
            }
        }
        puts("}");
    }

    return 0;
}
