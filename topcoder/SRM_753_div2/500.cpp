#include<bits/stdc++.h>

using namespace std;
class CCChecker2{
public:
    int N;
    bool che(int x){
        return x>=1 && x<=N;
    }
    string check(int n, vector <int> startRow, vector <int> startCol, vector <int> destRow, vector <int> destCol, vector <int> moveStartRow, vector <int> moveStartCol, vector <int> moveDestRow, vector <int> moveDestCol){
        vector<vector<int>> g(n+1,vector<int>(n+1,-1));
        int m = startRow.size();
        N = n;
        for(int i=0;i<m;i++){
            g[startRow[i]][startCol[i]]=i;
        }
        for(int i=0;i<moveStartRow.size();i++){
            int x=moveStartRow[i],y=moveStartCol[i],a=moveDestRow[i],b=moveDestCol[i];
            if(che(x) && che(y) && che(a) && che(b) && abs(x-a)+abs(y-b)==1 && g[x][y]!=-1 && g[a][b]==-1){
                g[a][b]=g[x][y];
                g[x][y]=-1;
            }
            else{
                return string("invalid");
            }
        }
        for(int i=0;i<m;i++){
            if(g[destRow[i]][destCol[i]]!=i){
                return string("invalid");
            }
        }
        return string("valid");
    }
};

int main()
{

    return 0;
}
