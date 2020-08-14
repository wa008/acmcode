#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
int n,m,k;
int ar[maxn];
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    sort(ar+1, ar+n+1);
    bool flag=1;
    int ins=0;
    for(int i=2;i<=n;i++){
        if(ar[i]==ar[i-1]){
            ins++;
            if(i-2>=1 && ar[i-1]==ar[i-2]+1)flag=0;
        }
    }
    if(n==1){
        if(ar[1]%2){
            ;
        }
        else{
            flag=0;
        }
    }
    else if(ins>=2 || (ar[1]==0 && ar[2]==0)){
        flag=0;
    }
    else{
        ll sum=0;
        for(int i=1;i<=n;i++){
            if(ar[i] < i-1){
                flag=0;
                break;
            }
            sum += ar[i]-(i-1);
        }
        if(sum%2==0)flag=0;
    }
    printf("%s\n", flag?"sjfnb":"cslnb");
    return 0;
}