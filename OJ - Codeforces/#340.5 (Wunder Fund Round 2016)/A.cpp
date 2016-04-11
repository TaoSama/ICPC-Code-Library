//
//  Created by TaoSama on 2016-01-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            ans.push_back(1);
            while(ans.size() > 1) {
                if(ans[ans.size() - 2] == ans[ans.size() - 1]) {
                    ans.pop_back();
                    ++ans[ans.size() - 1];
                } else break;
            }
        }
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}
