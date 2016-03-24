//
//  Created by TaoSama on 2016-02-05
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
const int L = 54;

const char op[7]="FLRUDB";
const int d[6][5][4]=
{
    {{1,3,9,7},{2,6,8,4},{43,19,48,18},{44,22,47,15},{45,25,46,12}},//F
    {{10,12,18,16},{11,15,17,13},{37,1,46,36},{40,4,49,33},{43,7,52,30}},//L
    {{19,21,27,25},{20,24,26,22},{54,9,45,28},{51,6,42,31},{48,3,39,34}},//R
    {{37,39,45,43},{38,42,44,40},{28,19,1,10},{29,20,2,11},{30,21,3,12}},//U
    {{16,7,25,34},{17,8,26,35},{46,48,54,52},{47,51,53,49},{18,9,27,36}},//D
    {{28,30,36,34},{29,33,35,31},{27,39,10,52},{24,38,13,53},{21,37,16,54}}//B
};

void trans(vector<int>& p, int o){
	for(int i = 0; i < 5; ++i){
		int t = p[d[o][i][3]];
		for(int j = 3; j; --j)
			p[d[o][i][j]] = p[d[o][i][j - 1]];
		p[d[o][i][0]] = t;
	}
}

char s[N];

vector<int> solve(){
    vector<int> p(L + 1);
    for(int i = 1; i <= L; ++i) p[i] = i;
	for(int i = 0; s[i]; ++i){
        int o = strchr(op, s[i]) - op;
        if(isalpha(s[i + 1]) || !s[i + 1]) trans(p, o);
        else {
			int cnt = s[i + 1] == '\'' ? 3 : 2;
			while(cnt--) trans(p, o);
			++i;
        }
	}
    return p;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		vector<int> p = solve();
		int ans = 1;  bool vis[L + 1] = {};
		for(int i = 1; i <= L; ++i){
			if(vis[i]) continue;
			int cycle = 0, tmp = i;
			do{
				++cycle;
				vis[tmp] = true;
				tmp = p[tmp];
			}while(tmp != i);
			ans = ans / __gcd(ans, cycle) * cycle;
		}
		static int kase = 0;
		printf("Case #%d:\n%d\n", ++kase, ans);
	}
    return 0;
}
