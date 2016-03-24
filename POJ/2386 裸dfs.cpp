#include <iostream>
#include <cstdio>

using namespace std;

char maze[105][105];
int n,m;
void dfs(int x,int y) {
    maze[x][y]='.';
    for(int i=-1; i<=1; ++i)
        for(int j=-1; j<=1; ++j) {
            int nx=x+i,ny=y+j;
            if(maze[nx][ny]=='W'&&nx>=0&&nx<n&&ny>=0&&ny<m)
                dfs(nx,ny);
        }
}
int main() {
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>n>>m) {
        int ans=0;
        for(int i=0; i<n; ++i) cin>>maze[i];

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(maze[i][j]=='W') {
                    ++ans;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}