//Nathan VandenHoek & David Baas

#include <iostream>
#include <vector>


int knapsack(std::vector<int> weight, std::vector<int> value, int maxWeight){
	int finalValues[weight.size() + 1][maxWeight + 1];

	for(unsigned int i = 0; i <= weight.size(); ++i){
		for(int w = 0; w <= maxWeight; ++w){
			if(i == 0 || w == 0)
				finalValues[i][w] = 0;
			else if (weight.at(i - 1) <= w)
				finalValues[i][w] = std::max(value.at(i-1) + finalValues[i-1][w-weight.at(i-1)], finalValues[i-1][w]);
			else
				finalValues[i][w] = finalValues[i-1][w];
		}
	}
	return finalValues[weight.size()][maxWeight];	
}

int main(int argc, char** argv){

	std::vector<int> weight = {15, 25, 45, 30, 23, 32};
	std::vector<int> value = {100, 350, 225, 67, 275, 168};
	std::cout << knapsack(weight, value, 100) << std::endl;
	return EXIT_SUCCESS;
}
