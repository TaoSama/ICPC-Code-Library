//
//	POJ 3292 Semi-prime H-numbers
//
//  Created by TaoSama on 2015-03-31
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

int n, H_num[N], H_semi[N];

void seive() {
    //在4n+1域中 0表示H-prime 1表示H-semi 2表示H-composite
    for(int i = 5; i < N; i += 4) {
        for(int j = 5; j < N; j += 4) {
            long long t = 1LL * i * j;
            if(t >= N) break;
            if(H_num[i] == 0 && H_num[j] == 0) H_num[t] = 1;
            else H_num[t] = 2;
        }
    }
    for(int i = 1; i < N; ++i) {
        H_semi[i] += H_semi[i - 1];
        if(H_num[i] == 1) H_semi[i] ++;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    seive();
    while(cin >> n && n) {
        cout << n << ' ' << H_semi[n] << endl;
    }
    return 0;
}
