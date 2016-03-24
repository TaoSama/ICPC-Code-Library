//
//  Created by TaoSama on 2015-08-09
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
const int N = 5e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n;

vector<int> prime;

bool notPrime[N];

void init() {
    for(int i = 2; i <= 5e6; ++i) {
        if(!notPrime[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 5e6; j += i)
                notPrime[j] = true;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(cin >> n) {
        vector<long long> ans;
        for(int i = 0; i < prime.size() && prime[i] < n; ++i) {
            if(n % prime[i] == 0) {
                ans.push_back(prime[i]);
                if(ans.size() == 2) break;
            }
        }
        if(ans.size() == 0) cout << "1\n0\n";
        else if(ans.size() == 2 && ans[0] * ans[1] != n)
            cout << 1 << '\n' << ans[0] * ans[1] << '\n';
        else {
            long long sq = ans[0] * ans[0];
            if(n % sq == 0 && sq != n) cout << 1 << '\n' << sq << '\n';
            else cout << 2 << '\n';
        }

    }
    return 0;
}
