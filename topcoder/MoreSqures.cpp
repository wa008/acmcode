#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+7;
const int maxm = 1e3+1;
const ll mod = 1e9+7;
int n,m;


class MoreSquares{
public:
    int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix){
        vector<int> xx(N,0),yy(N,0);
        int L = Xprefix.size();
        for(int i=0;i<L;i++)xx[i]=Xprefix[i],yy[i]=Yprefix[i];
        for(int i=L;i<N;i++){
            xx[i] = (xx[i-1] * 47 + 42) % SX;
            yy[i] = (yy[i-1] * 47 + 42) % SY;
        }
        int n = N;
        set<pair<int,int>> s1,s2;

        //for(int i=0;i<n;i++)cout<<xx[i]<<" "<<yy[i]<<endl;
        for(int i=0;i<n;i++)s1.insert(make_pair(xx[i],yy[i]));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int y = xx[j]-xx[i], x = yy[j]-yy[i];
                //cout<<xx[i]<<' '<<yy[i]<<' '<<xx[j]<<' '<<yy[j]<<" "<<x<<' '<<y<<endl;
                if(s1.count(make_pair(xx[i]+x, yy[i]-y))==1 && s1.count(make_pair(xx[j]+x,yy[j]-y))==0){
                    s2.insert(make_pair(xx[j]+x, yy[j]-y));
                }
                else if(s1.count(make_pair(xx[i]+x, yy[i]-y))==0 && s1.count(make_pair(xx[j]+x,yy[j]-y))==1){
                    s2.insert(make_pair(xx[i]+x, yy[i]-y));
                }
                if(s1.count(make_pair(xx[i]-x, yy[i]+y))==1 && s1.count(make_pair(xx[j]-x,yy[j]+y))==0){
                    s2.insert(make_pair(xx[j]-x, yy[j]+y));
                }
                else if(s1.count(make_pair(xx[i]-x, yy[i]+y))==0 && s1.count(make_pair(xx[j]-x,yy[j]+y))==1){
                    s2.insert(make_pair(xx[i]-x, yy[i]+y));
                }
            }
        }
        return int(s2.size());
    }
};

int main()
{
    MoreSquares mo;
    vector<int> v1,v2;
    v1.push_back(3);
    v1.push_back(0);
    v1.push_back(2);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(2);
    cout<<mo.countLocations(3,100,100,v1,v2)<<"\n";

    return 0;
}
