#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+7;

int n,m,ar[maxn];

char ch[maxn];
int main()
{
    int x,y,z;
    while(scanf("%d%d%d",&x,&y,&z)==3){
        for(int i=1;i<=x;i++){
            scanf("%s",ch);
            for(int in=0;in<z;in++){
                for(int j=0;j<y;j++){
                    for(int k=0;k<z;k++)printf("%c",ch[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
