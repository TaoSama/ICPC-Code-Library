//
//  Created by TaoSama on 2016-10-06
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

typedef long long LL;
LL A, B;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d%I64d", &A, &B);
        if(A > B) swap(A, B);

//      puts("");
//      for(int i = A; i <= B; ++i){
//          for(int j = A; j <= B; ++j){
//              if(1.0 * A / B + 1.0 * B / A <=
//                  1.0 * i / j + 1.0 * j / i){
//                      printf("%d %d\n", i, j);
//                  }
//          }
//      }
//      puts("");

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        if(A == B) {
            puts("1");
            printf("%I64d %I64d\n", A, B);
        } else {
            puts("2");
            printf("%I64d %I64d\n", A, B);
            swap(A, B);
            printf("%I64d %I64d\n", A, B);
        }
    }

    return 0;
}
