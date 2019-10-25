#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;


void exgcd(ll a,ll b,ll& d,ll &x,ll &y)
{
    if(!b){
        d=a,x=1,y=0;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
vector<int> v;
ll s = 0;
void dfs(ll x, ll last, ll pre, ll base = 1){
    if(x == 0){
        //cout << "s = " << pre << " " << pre * pre << "\n";
        return ;
    }
    if(x <= 0){
        return ;
    }
    for(int i=0;i<10;i++){
        ll mid = i * pre * 2 + i * i * base + last;
        if(mid % 10 == x % 10){
            dfs(x / 10, mid / 10, pre + base * i, base * 10);
        }
    }
}
int main()
{
    ll x = 987654321;
    //dfs(x, 0, 0, 1);
    scanf("%lld\n", &x);
    if(x < 9){
        printf("0\n");
    }
    else if(x == 9)printf("8\n");
    else{
        printf("72");
        for(int i = 0; i < x - 10; i++)printf("0");
        printf("\n");
    }
    return 0;
}
