//
//  Created by TaoSama on 2015-11-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int card[10];
char s[20];

bool dfs(int sum) {
    if(sum == 31) return false;
    for(int i = 1; i <= 6; ++i) {
        if(sum + i > 31) break;
        if(!card[i]) continue;
        --card[i];
        bool F = dfs(sum + i);
        ++card[i];
        if(!F) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        for(int i = 1; i <= 6; ++i) card[i] = 4;
        int sum = 0;
        int n = strlen(s);
        for(int i = 0; i < n; ++i) {
            --card[s[i] - '0'];
            sum += s[i] - '0';
        }
        printf("%s ", s);
        //这里必败和必胜反过来了
        if(dfs(sum)) printf("%c\n", "AB"[n & 1]); //必败
        else printf("%c\n", "BA"[n & 1]);  //必胜
    }
    return 0;
}
