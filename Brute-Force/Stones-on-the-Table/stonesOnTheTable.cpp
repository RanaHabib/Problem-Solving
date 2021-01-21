//https://codeforces.com/contest/266/problem/A

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
int main(){
    vector<char>color;
    int n; char temp; cin>>n;
    while(n--){
        cin>>temp;
        color.push_back(temp);
    }
    int count = 0;
    for(int i = 1; i < color.size(); i++){
        if(color[i] == color[i-1]){
            count++;
        }
    }
    cout<<count;
}
