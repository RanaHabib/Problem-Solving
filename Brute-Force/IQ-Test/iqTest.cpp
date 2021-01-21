//https://codeforces.com/contest/287/problem/A

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
int main()
{
   vector<string> x;
   int n =4;
   string temp;
   while(n--){
       cin>>temp;
       x.push_back(temp);
   }
   int count=0;
   bool flag = false;
   for(int i =0; i< 3 && !flag ; i++) {
       for (int j = 0; j < 3; j++) {
           if(x[i][j] != x[i][j+1]) count++;
           if(x[i][j] != x[i+1][j+1]) count++;
           if(x[i][j] != x[i+1][j]) count++;
 
           if(count == 1 || count ==0 || count == 3) {
               cout<<"YES";
               flag = true;
               break;
           }
           count =0;
       }
 
 
 
   }
    if(!flag)cout<<"NO";
}
