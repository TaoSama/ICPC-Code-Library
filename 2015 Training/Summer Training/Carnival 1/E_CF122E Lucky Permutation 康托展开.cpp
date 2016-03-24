//
//  Created by TaoSama on 2015-07-27
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

int per[20];
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
bool used[20];

//map the permutation to the k-th number
int KT(int *s, int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        //record the number of less than current number(coefficient)
        for(int j = i + 1; j < n; ++j)
            if(s[j] < s[i]) ++cnt;
        sum += cnt * fac[n - i - 1];
    }
    return sum;
}

//use the k-th number to recover the permutation [1...n]
void invKT(int *s, int k, int n) {
    k--; // 0-indexed need to minus 1
    for(int i = 0; i < n; ++i) {
        int cnt = k / fac[n - i - 1];
        //find the current cnt+1-th number so=
        for(int j = 0; j <= cnt; ++j)
            if(used[j]) ++cnt;
        s[i] = cnt + 1;
        used[cnt] = true;
        k %= fac[n - i - 1];
    }
}

vector<long long> lucky;

void dfs(string u) {
    if(u.size() > 9) return;
    if(u.size()) lucky.push_back(atoi(u.c_str()));
    dfs(u + "4");
    dfs(u + "7");
}

void init() {
    dfs("");
    lucky.push_back(4444444444LL);
    sort(lucky.begin(), lucky.end());
}

int n, k;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(cin >> n >> k) {
        if(n < 13 && k > fac[n]) {cout << "-1\n"; continue;}
        int change = 13;
        for(int i = 1; i < 13; ++i) if(k < fac[i]) {
                change = i;
                break;
            }

        invKT(per, k, change);
        int lef = n - change;
        int ans = 0;
        for(int i = 0; i < lucky.size() && lucky[i] <= n; i++) {
            if(lucky[i] <= lef) ans++;
            else {
                int pos = per[lucky[i] - lef - 1] + lef;
                for(int j = 0; j < lucky.size() && lucky[j] <= n; j++) {
                    if(pos == lucky[j]) {
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}


/*
http://blog.csdn.net/zhongkeli/article/details/6966805
*/
