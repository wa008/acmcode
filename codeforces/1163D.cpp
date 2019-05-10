#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

char ch[maxn],s[maxn],t[maxn];
int dp[maxn][60][60];
int ns[maxn],nt[maxn];

getfail(char *p,int *nex)//kmp找nex节点
{
    int k=strlen(p);
    nex[0]=0;
    nex[1]=0;
    for(int i=1;i<k;i++){
        int j=nex[i];
        while(j&&p[j]!=p[i])j=nex[j];
        nex[i+1]=p[i]==p[j]?j+1:0;
    }
}//kmp

int main()
{
    scanf("%s",ch+1);
    scanf("%s",s+1);
    scanf("%s",t+1);
    int a=strlen(ch+1);
    int b=strlen(s+1);
    int c=strlen(t+1);
    getfail(s+1, ns+1);
    getfail(t+1, nt+1);
    for(int i=1;i<=b;i++)ns[i]++;
    for(int i=1;i<=c;i++)nt[i]++;
    ns[0] = nt[0] = ns[1] = nt[1] = 0;
    //for(int i=0;i<=b;i++)cout<<ns[i]<<" ";cout<<"\n";
    //for(int i=0;i<=c;i++)cout<<nt[i]<<" ";cout<<"\n";
    for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)for(int k=0;k<=c;k++)dp[i][j][k] = -a-100;
    dp[0][0][0] = 0;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=0;i<=a;i++){
        int xx = ns[b], yy = nt[c];
        while(xx && s[xx]!=s[b])xx = ns[xx];
        while(yy && t[yy]!=t[c])yy = nt[yy];
        //cout<<"xx,yy = "<<xx<<" "<<yy<<endl;
        for(int j=0;j<b;j++){
            dp[i][j][yy] = max(dp[i][j][yy], dp[i][j][c]-1);
        }
        for(int j=0;j<c;j++){
            dp[i][xx][j] = max(dp[i][xx][j], dp[i][b][j]+1);
        }
        dp[i][xx][yy] = max(dp[i][xx][yy], dp[i][b][c]);
        if(i==a)break;
        for(int j=0;j<b;j++)for(int k=0;k<c;k++){
            for(int in=0;in<26;in++){
                if(ch[i+1]!='*' && ch[i+1] != in+'a')continue;
                char cc = in +'a';
                int xx=j+1, yy = k+1;
                while(xx && cc!=s[xx])xx = ns[xx];
                while(yy && cc!=t[yy])yy = nt[yy];
                if(i==3 && j==0 && k==0){
                    //cout<<xx<<" "<<yy<<" "<<dp[i][j][k]<<endl;
                }
                dp[i+1][xx][yy] = max(dp[i+1][xx][yy], dp[i][j][k]);
                /*
                if(s[j+1]==cc && t[k+1]==cc){
                    dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]);
                }
                else if(s[j+1]==cc){
                    dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k]);
                }
                else if(t[k+1]==cc){
                    dp[i+1][0][k+1] = max(dp[i+1][0][k+1], dp[i][j][k]);
                }
                else{
                    dp[i+1][0][0] = max(dp[i+1][0][0], dp[i][j][k]);
                }*/
            }
        }
    }
    /*
    for(int i=0;i<=a;i++){
        cout<<"i = "<<i<<endl;
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++)cout<<dp[i][j][k]<<" ";
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    cout<<"\n\n";
    for(int j=0;j<b;j++){
        for(int k=0;k<c;k++){
            cout<<dp[a][j][k]<<" ";
        }
        cout<<"\n";
    }*/
    int ans = -a-100;
    for(int j=0;j<b;j++){
        for(int k=0;k<c;k++){
            ans = max(ans, dp[a][j][k]);
        }
    }
    printf("%d\n", ans);
    return 0;
}