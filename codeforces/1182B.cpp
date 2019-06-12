#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,ar[maxn];

char ch[maxn][maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s", ch[i]+1);
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(flag)break;
        for(int j=1;j<=m;j++){
            if(flag)break;
            if(ch[i][j]=='*'){
                flag=1;
                while(i<=n && ch[i][j]=='*'){
                    if(j!=1 && j!=m && ch[i][j-1]=='*' && ch[i][j+1]=='*')break;
                    i++;
                }
                if(i>n || ch[i][j]!='*')break;
                ch[i][j]='.';
                int x=0;
                while(j+x+1<=m && ch[i][j+x+1]=='*'){
                    ch[i][j+x+1]='.';
                    x++;
                }
                if(x==0)break;
                x=0;
                while(j-x-1>0 && ch[i][j-x-1]=='*'){
                    ch[i][j-x-1]='.';
                    x++;
                }
                if(x==0)break;
                x=0;
                while(i+x+1<=n && ch[i+x+1][j]=='*'){
                    ch[i+x+1][j]='.';
                    x++;
                }
                if(x==0)break;
                x=0;
                while(i-x-1>0 && ch[i-x-1][j]=='*'){
                    ch[i-x-1][j]='.';
                    x++;
                }
                if(x==0)break;
                bool ff=1;
                for(int ii=1;ii<=n;ii++){
                    for(int jj=1;jj<=m;jj++){
                        if(ch[ii][jj]=='*'){
                            ff=0;
                            break;
                        }
                    }
                    if(!ff)break;
                }
                if(!ff)break;
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");

    return 0;
}