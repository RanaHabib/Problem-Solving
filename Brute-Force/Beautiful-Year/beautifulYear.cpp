//https://codeforces.com/contest/271/problem/A

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
 
void printUnique(int year){
    for(int i = year+1; ; i++){
        bool n[10] = {false};
        int num = i;
        while(num){
            if(n[num%10]) break;
            n[num%10] = true;
            num/=10;
        }
        if(!num){
            cout<<i;
            break;
        }
    }
 
}
 
int main()
{
    int year;cin>>year;
    printUnique(year);
    return 0;
}
