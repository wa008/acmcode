#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e5+7;
const ll mod = 998244353;

int n,m,ar[maxn];
char ch[maxn];
int main()
{
    int a,b,c,d;
    scanf("%d", &n);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    scanf("%s", ch+1);
    bool flag=1;
    if(d>c){
        while(a!=c || b!=d){
            if(a>n || b>n)break;
            if(b!=d){
                if(d<=b+2)b=d;
                else if(ch[b+2]=='.')b+=2;
                else if(ch[b+1]=='.')b++;
                else{
                    flag=0;
                    break;
                }
            }
            else{
                if(c<=a+2)a=c;
                else if(ch[a+2]=='.')a+=2;
                else if(ch[a+1]=='.')a++;
                else{
                    flag=0;
                    break;
                }
            }
        }
    }
    else{
        while(a!=c || b!=d){
            //cout<<a<<" "<<b<<endl;
            if(a>n || b>n)break;
            if(a!=c){
                if(c<=a+2 && b!=c){
                    a=c;
                    continue;
                }
                else if(ch[a+2]=='.' && b!=a+2){
                    a+=2;
                    continue;
                }
                else if(ch[a+1]=='.' && a+1!=b){
                    a++;
                    continue;
                }
            }
            if(b==d){
                flag=0;
                break;
            }
            if(ch[b+1]=='.' && a!=b+1)b++;
            else if(ch[b+2]=='.' && a!=b+2)b+=2;
            else{
                flag=0;
                break;
            }
        }
    }
    if(a!=c || b!=d)flag=0;
    printf("%s\n", flag?"Yes":"No");
    return 0;
}
