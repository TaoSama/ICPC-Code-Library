//
//  Created by TaoSama on 2016-11-19
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int ans = 32 - __builtin_clz(n);
        printf("%d\n", ans);

//        vector<int> v(n);
//        for(int i = 0; i < n; ++i) v[i] = i + 1;
//        int r = 0;
//        while(true) {
//          ++r;
//            sort(v.begin(), v.end());
//            int mid = v[v.size() / 2];
////            prln(mid);
//            for(int i = 0; i < v.size(); ++i) if(v[i] >= mid) v[i] -= mid;
//            vector<int> w;
//            for(int i = 0; i < v.size(); ++i){
//              if(v[i]) w.push_back(v[i]);
//            }
//            v = w;
//            if(v.size() == 0) break;
//        }
//        if(ans != r) {
//          printf("%d %d %d\n", n, ans, r);
//        }
    }

    return 0;
}
