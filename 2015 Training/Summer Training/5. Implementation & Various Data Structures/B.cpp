//
//  Created by TaoSama on 2015-07-23
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
#include <stack>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n && n){
		while(cin >> a[1] && a[1]){
			stack<int> s;
			for(int i = 2; i <= n; ++i) cin >> a[i];
			int A = 1, B = 1;
			bool ok = true;
			while(B <= n){
				if(A == a[B]) A++, B++;
				else if(s.size() && s.top() == a[B]) s.pop(), B++;
				else if(A <= n) s.push(A++);
				else {ok = false; break;}
			}
			cout << (ok ? "Yes" : "No") << '\n';
		}
		cout << '\n';
	}
	return 0;
}
