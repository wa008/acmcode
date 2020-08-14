#include<bits/stdc++.h>
using namespace std;


class PokerRound{
public:
    int amount(int t){
        int n=10000;
        if(t<=n && (n-t)%8==0){
            return n-(n-t)/8;
        }
        else return -1;
    }
};

int main()
{
    

    return 0;
}
