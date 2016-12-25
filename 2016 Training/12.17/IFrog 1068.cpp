//
//  Created by TaoSama on 2016-12-17
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
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    n = 7;
//    srand(time(0));
//
//    for(int _t = 1; _t <= n; ++_t) {
//        for(int i = 1; i <= 1e5; ++i) {
//            int b[100] = {};
//            int step = n / 3;
//            vector<int> v;
//            for(int t = 0; t < _t; ++t) {
//                int p = rand() % n;
//                b[p] ^= 1;
//                b[(p + step + 1) % n] ^= 1;
//                b[(p + step + 2) % n] ^= 1;
//                v.push_back(p);
//            }
//            if(accumulate(b, b + n, 0) == n) {
//                prln(_t);
//                for(int x : v) printf("%d ", x); puts("");
//                break;
//            }
//        }
//    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", n % 3 ? n : n / 3);
    }

    return 0;
}
