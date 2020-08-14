#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
int n,m,ar[maxn];
int s[maxn];
bool che(int x){
    cout<<"x = "<<x<<endl;
    for(int i=1;i<=n;i++){
        if(i+x == s[i]);
        else if(i + (n-i+1) <= x);
        else return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=1;i<=n;i++){
        if(ar[i]>0)s[ar[i]]=i;
    }
    int flag=-1,mn = n*2;
    for(int i=1;i<=n;i++){
        if(i<=s[i]){
            int now = s[i]-i;
            if(flag==-1)flag=now;
            else if(flag==now);
            else {
                flag=-2;
                break;
            }
        }
    }
    if(flag==-1){
        flag=0;
        for(int i=1;i<=n;i++){
            //if(i<=s[i])continue;
            int now = s[i] + n-i+1;
            if(flag<now)flag = now;
            //flag = max(flag, s[i] + n-i+1);
        }
    }
    else if(flag==-2){
        flag=0;
        for(int i=1;i<=n;i++){
            //if(i<=s[i])continue;
            int now = s[i] + n-i+1;
            if(flag<now)flag = now;
            //flag = max(flag, s[i] + n-i+1);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(i<=s[i])continue;
            int now = s[i] + n-i+1;
            if(now>flag){
                flag=-1;
                break;
            }
            //flag = max(flag, s[i] + n-i+1);
        }
        if(flag==-1){
            flag=0;
            for(int i=1;i<=n;i++){
                //if(i<=s[i])continue;
                int now = s[i] + n-i+1;
                if(flag<now)flag = now;
                //flag = max(flag, s[i] + n-i+1);
            }
        }
    }
    printf("%d\n", flag);
    return 0;
}