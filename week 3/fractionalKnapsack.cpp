/*
    Fractional knapsack problem: items can be divided,
    we need to find maximum
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
	double value;
	int weight;
};

double calculateValue(int capacity, vector<Item> items) {
	double value = 0.0;
  	for (auto item : items) {
  		if (capacity > item.weight) {
  			value += item.value * item.weight;
  			capacity -= item.weight;
  		} else {
  			value += item.value * capacity;
  			capacity = 0;
  		}

  		if (capacity == 0) {
  			return value;
  		}
  	}


  	return value;
}

bool cmp(Item a, Item b) { 
  return a.value > b.value; 
} 

int main() {
	int n;
	int capacity;
  	cin >> n >> capacity;
  	vector<Item> items;

  	int currentValue;
  	int currentWeight;
  	for (int i = 0; i < n; i++) { 
  		cin >> currentValue >> currentWeight;
  		double absoluteValue = (double) currentValue / (double) currentWeight;
  		items.push_back({absoluteValue, currentWeight});
  	}

  	sort(items.begin(), items.end(), cmp);

  	double optimalValue = calculateValue(capacity, items);

  	printf("%.4f\n", optimalValue);
  	return 0;
}
