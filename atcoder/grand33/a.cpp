#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 1e3+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn][maxn];
int vis[maxn][maxn];
queue<pair<int,int>> qu;
int desll[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",ch[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j]=='#'){
                qu.push(make_pair(i,j));
                vis[i][j] = 1;
            }
        }
    }
    int mx=1;
    while(qu.size()){
        int i=qu.front().first, j=qu.front().second;qu.pop();
        mx = max(mx, vis[i][j]);
        for(int in=0;in<4;in++){
            int nx = desll[in][0] + i;
            int ny = desll[in][1] + j;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                vis[nx][ny] = vis[i][j]+1;
                qu.push(make_pair(nx,ny));
            }
        }
    }
    printf("%d\n", mx-1);

    

    return 0;
}
