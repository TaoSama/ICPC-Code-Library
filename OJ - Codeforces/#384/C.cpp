//
//  Created by TaoSama on 2016-12-14
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//	for(int i = 1; i <= 10; ++i){
//		for(int x = 1; x <= 1000; ++x){
//			for(int y = x + 1; y <= 100; ++y){
//				for(int z = y + 1; z <= 100; ++z){
//					long double a  = (long double)2.0 / i;
//					long double b = (long double)1./x + (long double)1./y +(long double)1./z;
//					if(abs(a-b) < 1e-10){
//						printf("%d: %d %d %d\n", i, x, y, z);
//					}
//				}
//			}
//		}
//	}

	int n; cin >> n;
    if(n == 1) puts("-1");
    else cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;

    return 0;
}
