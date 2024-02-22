#include <iostream>
#include <limits>

int buyAndSellStocks(int prices[], int size){
    int buyPrice = std::numeric_limits<int>::max();
    int maxProfit = 0;
    
    for(int i = 0; i < size; i++){
        if(buyPrice < prices[i]){
            int profit = prices[i] - buyPrice;
            maxProfit = std::max(maxProfit, profit);
        } else {
            buyPrice = prices[i];
        }
    }
    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices)/sizeof(prices[0]);
    int result = buyAndSellStocks(prices, size);
    
    std::cout << result;

    return 0;
}
