#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 1e3+1;
const ll mod = 998244353;
int n,m;

bool che(int i,int j){
    int x1=i/m,y1=i%m;
    int x2=j/m,y2=j%m;
    if(x1!=x2 && y1!=y2 && x1+y1!=x2+y2 && x1-y1!=x2-y2){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int fir=1;fir<=t;fir++){
        scanf("%d%d",&n,&m);
        //cout<<"n,m = "<<n<<" "<<m<<"\n";
        if(min(n,m)==1)continue;
        int flag=0;
        int s=n*m;
        vector<int> ar(s,0);
        for(int i=0;i<s;i++)ar[i]=i;
        //for(int i=0;i<s;i++)cout<<ar[i]<<" ";;cout<<endl;
        vector<vector<int>> g(s,vector<int>(s,0));
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                int x1=i/m,y1=i%m;
                int x2=j/m,y2=j%m;
                if(x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2)continue;
                g[i][j]=1;
            }
        }
        for(int step=0;step<1000;step++){
            random_shuffle(ar.begin(), ar.end());
            //for(int i=0;i<m*n;i++)cout<<ar[i]<<' ';cout<<endl;
            int ff=1;
            for(int i=0;i<s-1;i++){
                int k=i+1;
                for(;k<s && !che(ar[i],ar[k]); k++);
                if(k>=s){
                    ff=0;
                    break;
                }
                assert(k<s);
                swap(ar[i+1],ar[k]);
            }
            if(ff){
                flag=1;
                break;
            }
        }
        if(flag){
            printf("Case #%d: POSSIBLE\n",fir);
            //continue;
            for(int i=0;i<n*m;i++){
                printf("%d %d\n",ar[i]/m+1,ar[i]%m+1);
            }
        }
        else{
            //cout<<"n,m = "<<n<<" "<<m<<endl;
            printf("Case #%d: IMPOSSIBLE\n",fir);
        }
    }
    return 0;
}
