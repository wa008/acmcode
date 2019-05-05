#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn];

vector<int> v[maxn];
vector<int> cmp[maxn];
bool vis[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=i+i;j<=n;j+=i)cmp[j].push_back(i);
    }
    int fff=1;
    for(int i=1;i<=m;i++){
        int a,b;scanf("%d%d",&a,&b);
        a--;b--;
        int x=min(a,b),y = max(a,b);
        if(n%2==0){
            if(y-x != n/2)fff=0;
        }
        else fff=0;
        int len = y-x;
        if(len<=n/2){
            v[len].push_back(x);
        }
        else{
            v[n-len].push_back(y);
        }
    }
    if(fff){
        printf("Yes\n");
        return 0;
    }
    /*
       for(int i=0;i<n;i++){
       for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";cout<<"\n";
       }*/
    int flag=1;
    ll pre = 1;
    for(int i=0;i<n;i++){
        sort(v[i].begin(), v[i].end());
        if(v[i].size()== 1){
            flag=0;
            break;
        }
        if(v[i].size()==0)continue;
        ll len=n;
        for(int j: cmp[v[i].size()]){
            if(j>v[i].size()/2){
                flag=0;
                break;
            }
            int ff=1;
            int Len = v[i][j] - v[i][0];
            for(int k=0;k<v[i].size();k++){
                if((v[i][k]+Len)%n != v[i][(k+j)%v[i].size()]){
                    ff=0;
                    break;
                }
            }
            if(ff){
                len = Len;
                break;
            }
        }
        //for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";cout<<"\n";
        if(!flag)break;
        pre = pre*len/__gcd(pre, len);
    }
    if(flag){
        if(pre>=n)flag=0;
    }
    if(flag){
        for(int i=0;i<n;i++){
            for(int j : v[i])vis[j]=1;
            for(int j : v[i])assert(vis[(j+pre)%n]==1);
            for(int j : v[i])vis[j]=0;
        }
    }
    //cout<<"pre = "<<pre<<endl;
    printf("%s\n",flag==1?"Yes":"No");


    return 0;
}