//
//  Created by TaoSama on 2015-05-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, k;
char s[N], d[10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d ", &t);
    int kase = 0;
    while(t--) {
        gets(s + 1); gets(d);
        k = atoi(d);
        int n = strlen(s + 1), all = 0;
        int p = (n + k - 1) / k ;
        int can = n % k;
        //cout << p << ' ' << can << endl;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= p; ++i) {
            int ct = 0;
            //printf("%d: ", i);
            for(int j = i; j <= n; j =
                        j + p + ((ct > can && can > 0) ? - 1 : 0)) {
                ++ct;
                //printf("%d", j);
                printf("%c", s[j]);
                if(++all == n) break;
                //putchar(' ');
            }
            //printf("\n");
        }
        printf("\n");
    }
    return 0;
}
