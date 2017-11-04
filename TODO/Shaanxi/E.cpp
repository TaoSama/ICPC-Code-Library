//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    bool mark=0;
	bool type=0;
	while(gets(s)){
		int n=strlen(s);
		string a;
		bool mark1=0;
		for(int j=0;j<n;j++){
			if(!mark&&s[j]=='"') mark1^=1;

			if(!mark1){
				if(j>=1&&s[j-1]=='*'&&s[j]=='/'){
					if(mark&&type){
						mark=0;
						continue;
					}
				}
				if(j+1<n&&s[j]=='/'&&s[j+1]=='*'){
					if(!mark){
						mark=1;
						type=1;
					}
				}
				if(j+1<n&&s[j]=='/'&&s[j+1]=='/'){
					if(!mark){
						mark=1;
						type=0;
					}
				}
			}
			//printf("j = %d mark = %d\n",j,mark)
			if(mark) continue;
			a.push_back(s[j]);
		}
		if(!type) mark=0;
		while(a.size()&&a.back()==' ') a.pop_back();
		if(!a.size()) continue;
		printf("%s\n",a.c_str());
	}

    return 0;
}
