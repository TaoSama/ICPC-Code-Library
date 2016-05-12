//
//  Created by TaoSama on 2016-02-27
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    //2 5
    scanf("%d", &m);
    long long two = 0, five = 0;
    vector<int> ans;
    for(int i = 1; i <= 1e6; ++i) {
        int t = i;
        while(t % 2 == 0) {
            ++two;
            t /= 2;
        }
        while(t % 5 == 0) {
            ++five;
            t /= 5;
        }
        long long zero = min(two, five);
        if(zero == m) ans.push_back(i);
    }
    if(ans.size()) {
        printf("%d\n", ans.size());
        for(int x : ans) printf("%d ", x); puts("");
    } else puts("0");
    return 0;
}
