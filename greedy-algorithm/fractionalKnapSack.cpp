#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByfraction(const pair<int,float> &a,const pair<int,float> &b){
    return (a.second < b.second);
}

int fractionalKnapsack(vector<int> values,vector<int> weights, int n, int W){
    vector<pair<int,float>> valuePerWeight;
    for (int i = 0; i < values.size(); i++)
        valuePerWeight.push_back(make_pair(i,values[i]/weights[i]));

    sort(valuePerWeight.begin(), valuePerWeight.end(), sortByfraction);

    int weightLeft = W;
    int maxValue = 0;
    for(int i = valuePerWeight.size()-1; i >= 0; i--){
        weightLeft = weightLeft - weights[valuePerWeight[i].first];

        if(weightLeft >= 0) {
            valuePerWeight[i].second = 1;
        }
        else {
            weightLeft += weights[valuePerWeight[i].first];
            valuePerWeight[i].second = (float)(weightLeft) / (float)(weights[valuePerWeight[i].first]);
        }
        maxValue += values[valuePerWeight[i].first]*valuePerWeight[i].second;
    }



    return maxValue;

}

int main(){

    int n = 3;
    int W = 50;
    vector<int> values{60,100,120};
    vector<int> weights{10,20,30};

    int maxValue = fractionalKnapsack(values, weights, n, W);
    cout<<maxValue<<endl;

    return 0;
}
