#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

ll n,f1,f2,f3,c;
const int sz=14;
struct node{
    ll v[sz][sz];
    void mem(){
        memset(v,0,sizeof(v));
    }
    void prin(){
        cout<<"node = \n";
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++)cout<<v[i][j]<<" ";cout<<"\n";
        }
    }
};
node cul(node& n1, node& n2){
    node ans;
    ans.mem();
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                ans.v[i][j] = (ans.v[i][j] + n1.v[i][k]*n2.v[k][j])%(mod-1);
            }
        }
    }
    return ans;
}
node node_mypow(node no, ll x){
    node ans;
    ans.mem();
    for(int i=0;i<sz;i++)ans.v[i][i]=1;
    while(x>0){
        if(x&1)ans = cul(ans, no);
        no = cul(no, no);
        x/=2;
    }
    return ans;
}
ll mypow(ll a, ll b){
    ll ans=1;
    while(b>0){
        if(b&1)ans = ans*a%mod;
        b/=2;
        a = a*a%mod;
    }
    return ans;
}
int main()
{
    scanf("%lld%lld", &n, &f1);
    scanf("%lld%lld", &f2, &f3);
    scanf("%lld", &c);
    node no;
    no.mem();
    for(int i=4;i<=7;i++)no.v[i][i-4]=1;
    for(int i=8;i<=11;i++)no.v[i][i-4]=1;
    for(int i=0;i<11;i+=4)for(int j=0;j<=3;j++){
        no.v[i+j][8+j]=1;
    }
    no.v[12][11]=1;
    no.v[12][12]=1;
    no.v[13][12]=2;
    no.v[13][13]=1;
    //no.prin();
    node ans = node_mypow(no, n-3);
    //ans.prin();
    node be;
    be.mem();
    be.v[0][0]=1;
    be.v[0][5]=1;
    be.v[0][10]=1;
    be.v[0][12]=2;
    be.v[0][13]=1;
    //printf("be = \n");
    //be.prin();
    ans = cul(be, ans);
    //ans.prin();
    ll p=1;
    p = p * mypow(f1, ans.v[0][8]) % mod;
    p = p * mypow(f2, ans.v[0][9]) % mod;
    p = p * mypow(f3, ans.v[0][10]) % mod;
    p = p * mypow(c, ans.v[0][11]) % mod;
    printf("%lld\n", p);
    return 0;
}