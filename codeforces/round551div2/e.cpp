#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+7;

int x1,x2,y1,y2;
int main()
{
    x1=x2=y1=y2=0;
    int n,m;scanf("%d",&n);
    int flag=0,r1=0,r2=0,c1=0,c2=0;
    for(int i=1;i<n;i++){
        printf("? %d %d %d %d",i,1,i,n);
        fflush(stdout);
        int x;scanf("%d",&x);x%=2;
        if(x){
            flag=1;
            if(r1==0)r1=i;
            else r2=i;
        }
    }
    if(flag && r2==0)r2=n;
    if(flag){
        int l=1,r=n;
        while(l<r){
            int mid = l+r>>1;
            printf("? %d %d %d %d",r1,l,r1,mid);
            fflush(stdout);
            int x;scanf("%d",&x);x%=2;
            if(x){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        x1=r1;
        l=1,r=n;
        while(l<r){
            int mid = l+r>>1;
            printf("? %d %d %d %d",r2,l,r2,mid);
            fflush(stdout);
            int x;scanf("%d",&x);x%=2;
            if(x){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        x2=r2;y2=l;
    }

    return 0;
}
