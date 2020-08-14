#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+7;
int a1[1010],a2[1010];
int ar1[maxn][maxn],ar2[maxn][maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&ar1[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&ar2[i][j]);
    int flag=1;
    int l1=0,l2=0;
    for(int i=1;i<=n;i++){
        int x=i,y=1;
        l1=0,l2=0;
        while(x>=1 && y<=m){
            a1[l1++]=ar1[x][y];
            x--;
            y++;
        }
        x=i,y=1;
        while(x>=1 && y<=m){
            a2[l2++]=ar2[x][y];
            x--;
            y++;
        }
        sort(a1,a1+l1);
        sort(a2,a2+l2);
        for(int j=0;j<l1;j++){
            if(a1[j]!=a2[j]){
                flag=0;
                break;
            }
        }
        if(!flag)break;
    }
    for(int i=m;i>1;i--){
        int x=n,y=i;
        l1=0,l2=0;
        while(x>=1 && y<=m){
            a1[l1++]=ar1[x][y];
            x--;
            y++;
        }
        x=n,y=i;
        while(x>=1 && y<=m){
            a2[l2++]=ar2[x][y];
            x--;
            y++;
        }
        sort(a1,a1+l1);
        sort(a2,a2+l2);
        for(int j=0;j<l1;j++){
            if(a1[j]!=a2[j]){
                flag=0;
                break;
            }
        }
        if(!flag)break;
    }
    printf("%s\n",flag?"YES":"NO");

    return 0;
}
