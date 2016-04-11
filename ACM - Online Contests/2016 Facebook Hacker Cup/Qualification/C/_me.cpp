//
//  Created by TaoSama on 2016-01-10
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

int n, p, a[N];

typedef long long LL;

LL get(pair<int, int> x){
	int l = x.second - x.first;
	return 1LL * l * (l + 1) >> 1;
}

int main() {
//    freopen("the_price_is_correct.txt", "r", stdin);
//  freopen("the_price_is_correct_out.txt","w",stdout);
    ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &p);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int l = 1, r = 1, sum = 0;
        vector<pair<int, int> > v; v.push_back({0, 0});
        while(r <= n){
			while(r <= n && sum + a[r] <= p) sum += a[r++];
            if(sum <= p) v.push_back({l, r});
            sum -= a[l++];
        }

        LL ans = 0;
        for(int i = 1; i < v.size(); ++i){
			pair<int, int> &x = v[i], &y = v[i - 1];
			ans += get(x);
			if(x.first >= y.second) continue;
			ans -= get({x.first, y.second});
        }

        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans);
	}
    return 0;
}
