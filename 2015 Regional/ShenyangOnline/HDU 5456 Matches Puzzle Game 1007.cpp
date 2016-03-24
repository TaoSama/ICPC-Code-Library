//
//  Created by TaoSama on 2015-09-25
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

typedef long long LL;

int n, m;
LL dp[505][2][2][2]; //left, carry, place B, place C
int need[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void add(LL& x, LL y) {
    x += y;
    if(x >= m) x -= m;
}

LL dfs(int n, bool carry, bool B, bool C) {
    LL& ret = dp[n][carry][B][C];
    if(~ret) return ret;
    if(n == 0) {
        if(!carry && !B && !C) return ret = 1;
        return ret = 0;
    }

    ret = 0;
    if(B && C) {
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                int sum = need[i] + need[j] + need[(i + j + carry) % 10];
                if(sum > n) continue;
                bool nxt = i + j + carry >= 10;  //check next carry
                //always can continue to place B & C
                add(ret, dfs(n - sum, nxt, 1, 1));
                if(i) add(ret, dfs(n - sum, nxt, 0, 1)); //choose not to place B
                if(j) add(ret, dfs(n - sum, nxt, 1, 0)); //choose not to place C
                if(i && j) add(ret, dfs(n - sum, nxt, 0, 0)); //choose neither place
            }
        }
    } else if(B) {
        for(int i = 0; i < 10; ++i) {
            int sum = need[i] + need[(i + carry) % 10];
            if(sum > n) continue;
            bool nxt = i + carry >= 10;
            add(ret, dfs(n - sum, nxt, 1, 0));
            if(i) add(ret, dfs(n - sum, nxt, 0, 0));
        }
    } else if(C) {
        for(int j = 0; j < 10; ++j) {
            int sum = need[j] + need[(j + carry) % 10];
            if(sum > n) continue;
            bool nxt = j + carry >= 10;
            add(ret, dfs(n - sum, nxt, 0, 1));
            if(j) add(ret, dfs(n - sum, nxt, 0, 0));
        }
    } else {
        if(carry && n == need[1]) ret = 1;
    }
    return ret;
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
        scanf("%d%d", &n, &m);
        n -= 3; //subtract - & = signs' cost
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %I64d\n", ++kase, dfs(n, 0, 1, 1));
    }
    return 0;
}
