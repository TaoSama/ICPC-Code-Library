//
//  Created by TaoSama on 2016-06-09
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

int vis[105];
vector<int> prime;

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 2; i <= 100; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j <= 100; j += i) vis[j] = true;
    }

    vector<int> test;
    for(int x : prime) {
        bool ok = false;
        for(int y : prime) if(x != y && x * y <= 100) ok = true;
        if(!ok) continue;
        test.push_back(x);
        if(x * x <= 100) test.push_back(x * x);
    }
    sort(test.begin(), test.end());
    test.resize(unique(test.begin(), test.end()) - test.begin());
//    prln(test.size());
//  for(auto x : test) printf("%d ", x); puts("");

    int yes = 0;
    for(int x : test) {
        printf("%d\n", x);
        fflush(stdout);
        char buf[10]; scanf("%s", buf);
        if(!strcmp(buf, "yes")) ++yes;
    }
    puts(yes > 1 ? "composite" : "prime");
    fflush(stdout);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
