//
//  HDU 2577 How to Type
//
//  Created by TaoSama on 2015-02-08
//  Copyright (c) 2014 TaoSama. All rights reserved.
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int t, on[105], off[105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin>>t){
		while(t--){
			char s[105]; cin>>(s+1);
			int l = strlen(s+1);
			CLR(on,0x3f); CLR(off,0x3f);
			on[0] = 1; off[0] = 0;
			for(int i=1;i<=l;++i){
				if(islower(s[i])){
					on[i] = min(on[i-1]+2,off[i-1]+2); //��shift��, ���꿪��
					off[i] = min(on[i-1]+2,off[i-1]+1); //�صƴ�, ֱ�Ӵ�
				}
				else{
					on[i] = min(on[i-1]+1,off[i-1]+2); //ֱ�Ӵ�, ��shift��
					off[i] = min(on[i-1]+2,off[i-1]+2); //����ص�, ��shift��
				}
			}
			++on[l]; //������ص�
			cout<<min(on[l],off[l])<<endl;
		}
	}
	return 0;
}
