#include<bits/stdc++.h>
using namespace std;

const int maxn = 251;
const int des[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int n,m;
int vis[maxn][maxn];
char ch[maxn][maxn];

queue<int> qu;
bool che(int x){
    //cout<<"x = "<<x<<endl;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j]=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j]=='1'){
                vis[i][j]=0;
                qu.push(i*m+j);
                cnt++;
            }
        }
    }
    while(qu.size()){
        int i = qu.front()/m,j = qu.front()%m;
        qu.pop();
        if(vis[i][j]==x)continue;
        for(int k=0;k<4;k++){
            int ni = i + des[k][0];
            int nj = j + des[k][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==-1){
                vis[ni][nj] = vis[i][j]+1;
                qu.push(ni*m+nj);
                cnt++;
            }
        }
    }
    if(cnt == n*m)return 1;
    int mx1=-10000000,mx2=-10000000;
    int mn1=10000000,mn2=10000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(vis[i][j]==-1){
            //cout<<"i,j = "<<i<<" "<<j<<endl;
            mx1 = max(mx1, i+j);
            mn1 = min(mn1, i+j);
            mx2 = max(mx2, i-j);
            mn2 = min(mn2, i-j);
        }
    }
    //cout<<mx1<<" "<<mn1<<endl;
    //cout<<mx2<<" "<<mn2<<endl;
    if(mx1-x<=mn1+x && mx2-x<=mn2+x){
        if(mn1+x>=mx2-x){
            if((mn1 + mx2)&1){
                if(mx1-x<mn1+x || mx2-x<mn2+x)return 1;
                else return 0;
            }
            else return 1;
        }
    }
    return 0;
}
int main()
{
    int t;scanf("%d",&t);
    for(int fir = 1; fir<=t; fir++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%s",ch[i]);
        int l=0,r=m+n;
        while(l<r){
            int mid = l+r>>1;
            if(che(mid))r=mid;
            else l=mid+1;
        }
        printf("Case #%d: %d\n",fir,l);
    }
    return 0;
}
