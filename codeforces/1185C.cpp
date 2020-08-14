#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];

int n1[maxn], n2[maxn];
int aa[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    int ins=0,sum=0,ans=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        //cout<<"x = "<<x<<endl;
        int las = m-x-sum;
        while(las<0 && ins>=1){
            //cout<<ins<<" "<<las<<endl;
            int now = min(n2[ins], (abs(las)+ins-1)/ins);
            ans += now;
            las += ins*now;
            sum -= ins*now;
            n1[ins] += now;
            n2[ins] -= now;
            //if(now>0)cout<<ins<<" "<<now<<" "<<sum<<" "<<las<<"\n";
            if(n2[ins]==0)ins--;
        }
        assert(ins>=0);
        if(ins<1)ins=1;
        while(las>=ins && ins<=101){
            //cout<<ins<<" "<<las<<"\n";
            int now = min(n1[ins], las/ins);
            ans -= now;
            las -= ins*now;
            sum += ins*now;
            n1[ins] -= now;
            n2[ins] += now;
            //cout<<"now = "<<now<<"\n";
            if(n1[ins]==0)ins++;
        }
        aa[i] = ans;
        if(x<ins){
            sum += x;
            n2[x] ++ ;
        }
        else{
            ans++;
            n1[x] ++ ;
        }
        //cout<<"ins = "<<ins<<" "<<sum<<endl;
        //for(int i=1;i<10;i++)cout<<n1[i]<<" ";cout<<"\n";
        //for(int i=1;i<10;i++)cout<<n2[i]<<" ";cout<<"\n";
    }
    for(int i=1;i<=n;i++)printf("%d%c", aa[i], i==n?'\n':' ');
    return 0;
}