#include<bits/stdc++.h>
using namespace std;


int ch[50*1000+10][30];
int val[50*1000+10];
const int sz = 26;
int node_sz,n;
void init(){
    for(int i=0;i<=node_sz;i++)val[i]=0;
    node_sz=0;
    memset(ch[node_sz],0,sizeof(ch[node_sz]));
}

void insert(char *c,int len){
    int now=0;
    val[now]++;
    for(int i=0;i<len;i++){
        int ins=c[i]-'A';
        if(ch[now][ins]==0){
            ch[now][ins]=++node_sz;
            memset(ch[node_sz],0,sizeof(ch[node_sz]));
        }
        now = ch[now][ins];
        val[now]++;
        //cout<<ins<<" "<<now<<"\n";
    }
}
int dfs(int u){
    if(u!=0 && val[u]/2<=1){
        //cout<<"u,s = "<<u<<" "<<val[u]/2*2<<"\n";
        return val[u]/2*2;
    }
    int ans=0,s=0;
    for(int i=0;i<sz;i++){
        if(ch[u][i]!=0){
            s += dfs(ch[u][i]);
        }
    }
    //cout<<"u,s = "<<u<<" "<<s<<endl;
    ans = s;
    if(u!=0)ans += max(0,min(2,(val[u]-s)/2*2));
    return ans;
}
char c[100];
int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",c+1);
            int len = strlen(c+1);
            for(int i=1;i<=len/2;i++){
                swap(c[i],c[len-i+1]);
            }
            //cout<<"c = "<<c+1<<endl;
            insert(c+1,len);
        }
        int ans = dfs(0);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
