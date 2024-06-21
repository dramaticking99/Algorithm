#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class KnapSack {
    
    private:
    int knapSackCapacity;
    float maximumProfit = 0;
    vector<int>profits;
    vector<int>weights;
    vector<float>pByW;

    void generatePByWArray() {
        for(int i = 0; i < profits.size(); i++) {
            float ratio = static_cast<float>(profits[i]) / weights[i];
            pByW.push_back(ratio);
        }
    }

    void sortpByW() {
        bubbleSort();
    }

    void calculateMaxProfit() {
        int maxWeight = knapSackCapacity;
        int index = 0;
        maxWeight = maxWeight - weights[index]; 
        while(maxWeight > 0) {
            maximumProfit = maximumProfit + profits[index++];
            maxWeight = maxWeight - weights[index]; 
            
        }

        if(maxWeight < 0) {
            float reqWeight = weights[index] + maxWeight;
            float profit = (static_cast<float>(reqWeight)/weights[index])*profits[index];
            maximumProfit = maximumProfit + profit;
        }
    }

    void bubbleSort() {
    int n = pByW.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (pByW[j] < pByW[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                float temp = pByW[j];
                pByW[j] = pByW[j + 1];
                pByW[j + 1] = temp;

                temp = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = temp;

                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
            }
        }
    }
}

    public:
    KnapSack(vector<int>&profitsArray, vector<int>&weightsArray, int &capacity) {
        profits = profitsArray;
        weights = weightsArray;
        knapSackCapacity = capacity;
    }        

    float getMaximumProfit() {
        generatePByWArray();
        sortpByW();
        calculateMaxProfit();
        return maximumProfit;
    }
};

int main() {
    vector<int>profits = {10,5,15,7,6,18,3};
    vector<int>weights = {2,3,5,7,1,4,1};
    int capacity = 15;
    
    KnapSack* sack = new KnapSack(profits,weights,capacity);

    float profit = sack->getMaximumProfit();

    cout<<"the maximum profit is : "<<profit;

    delete sack;
}