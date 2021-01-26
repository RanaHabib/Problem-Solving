#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define ll long long
int alice[4][4]={},bob[4][4]={},flag[4][4]={},a=0,b=0;
ll k,aliceScore,bobScore;

void calculateScore(int x,int y){
    if(x==y) return;
    if(x==3 && y==2 || x==2 && y==1 || x==1 && y==3)
        aliceScore++;
    else
        bobScore++;
}

void calcWinner(){
    cin>>k>>a>>b;
    if(k==1){
        calculateScore(a,b);
        cout<<aliceScore<<" "<<bobScore;
        return;
    }
    else if(k>50){
        int firstA=a, firstB=b;
        for(int i = 1; i <= 3; i++)
            cin>>alice[i][1]>>alice[i][2]>>alice[i][3];

        for(int i = 1; i <= 3; i++)
            cin>>bob[i][1]>>bob[i][2]>>bob[i][3];

        vector<pair<int,int>> graph;
        ll i = 0;

        while(i++<k && flag[a][b]==0){
            flag[a][b] = i;
            graph.emplace_back(a,b);
            int tempA = a, tempB = b;
            a = alice[tempA][tempB];
            b = bob[tempA][tempB];
        }

        ll cycleLength = i - flag[a][b];
        int cycleIndex = i - cycleLength - 1;

        a = graph[cycleIndex].first;
        b = graph[cycleIndex].second;
        ll j = 0;
        while(j++<cycleLength){
            calculateScore(a,b);
            int tempA = a, tempB = b;
            a = alice[tempA][tempB];
            b = bob[tempA][tempB];
        }


        ll cycleOccurrence = (k-cycleIndex)/cycleLength;
        aliceScore *= (cycleOccurrence);
        bobScore *= (cycleOccurrence);

        ll remainderCycles = (k-cycleIndex) % cycleLength;
        j = 0;
        a = graph[cycleIndex].first;
        b = graph[cycleIndex].second;
        while(j++<remainderCycles){
            calculateScore(a,b);
            int tempA = a, tempB = b;
            a = alice[tempA][tempB];
            b = bob[tempA][tempB];
        }

        j = 1;
        a = firstA; b = firstB;
        while(j++<=cycleIndex){
            calculateScore(a,b);
            int tempA = a, tempB = b;
            a = alice[tempA][tempB];
            b = bob[tempA][tempB];
        }

        cout<<aliceScore<<" "<<bobScore;
    }
    else{
        for(int i = 1; i <= 3; i++)
            cin>>alice[i][1]>>alice[i][2]>>alice[i][3];

        for(int i = 1; i <= 3; i++)
            cin>>bob[i][1]>>bob[i][2]>>bob[i][3];
        int j =0;
        while(j++<k){
            calculateScore(a,b);
            int tempA = a, tempB = b;
            a = alice[tempA][tempB];
            b = bob[tempA][tempB];
        }

        cout<<aliceScore<<" "<<bobScore;
    }
}
int main() {
    calcWinner();

    return 0;
}

