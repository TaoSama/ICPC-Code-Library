//
//
//
//  Created by TaoSama on 2015-04-12
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(scanf("%d", &n) == 1){
		if(n == 1 || n == 2) printf("1\n1\n");
		else if(n == 3) printf("2\n1 3\n");
		else if(n == 4) printf("4\n3 1 4 2\n");
		else{
			printf("%d\n", n);
			for(int i = 1; i <= n; i += 2)
				printf("%d ", i);
			for(int i = 2; i <= n; i += 2)
				printf("%d ", i);
			printf("\n");
		}
	}
	return 0;
}
