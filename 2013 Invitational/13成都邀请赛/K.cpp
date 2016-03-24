//
//  Created by TaoSama on 2015-05-11
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
const int N = 1e6 + 10;

int a[10], b[10];
char ss[N], tt[N];

void output() {
    for(int i = 0; i <= 9; ++i)
        cout << i << ' ';
    cout << endl;
    for(int i = 0; i <= 9; ++i)
        cout << a[i] << ' ';
    cout << endl;
    for(int i = 0; i <= 9; ++i)
        cout << b[i] << ' ';
    cout << endl;
}

int getFirst() {
    for(int k = 9; k >= 0; --k) {
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <= 9; ++j) {
                if((i + j) % 10 == k && a[i] && b[j]) {
                    --a[i]; --b[j];
                    printf("%d", k);
                    return k;
                }
            }
        }
    }
    return 10;
}

void getOther() {
    for(int k = 9; k >= 0; --k) {
        for(int i = 0; i <= 9; ++i) {
            for(int j = 0; j <= 9; ++j) {
                while((i + j) % 10 == k && a[i] && b[j]) {
                    printf("%d", k);
                    --a[i]; --b[j];
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        scanf("%s%s", ss, tt);
        for(int i = 0; ss[i]; ++i) {
            a[ss[i] - '0']++;
            b[tt[i] - '0']++;
        }

        //output();
        printf("Case #%d: ", ++kase);
        //if(strlen(ss) == 1)
        //  printf("%d", (ss[0] + tt[0] - 2 *'0') % 10);
        if(getFirst())  getOther();
        printf("\n");
    }
    return 0;
}
