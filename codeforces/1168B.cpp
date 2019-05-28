#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
int ar[maxn];
char ch[maxn];


void test(){
    n=1e6;
    for(int i=1;i<=n;i++){
        ch[i] = '0' + (rand()%2);
    }
    ch[n+1]='\0';
}
int main()
{
    scanf("%s", ch+1);
    //for(int ra=0;ra<=100;ra++){
    //srand(ra*100);
    //test();
    n = strlen(ch+1);
    for(int i=1;i<=n;i++)ar[i] = n+1;
    ll all=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(i-1) && j<=(n-j);j++){
            all++;
            if(ch[i]==ch[i+j] && ch[i]==ch[i-j]){
                ar[i-j] = min(ar[i-j], i+j);
                break;
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<i<<" ";cout<<"\n";
    //for(int i=1;i<=n;i++)cout<<ch[i]<<" ";cout<<"\n";
    //for(int i=1;i<=n;i++)cout<<ar[i]<<" ";cout<<"\n";
    for(int i=n-1;i>=1;i--){
        ar[i] = min(ar[i], ar[i+1]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans += (n-ar[i]+1);
    }
    printf("%lld\n", ans);
    //cout<<all<<"\n"<<n<<endl;
    //cout<<"all/n = "<<all/n<<endl;
    //}
    return 0;
}