#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> products;
public:
    ProductOfNumbers() {
        products.push_back(1);  // Initial product to handle multiplication properly
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();  // Clear the products as any product now will be zero
            products.push_back(1);  // Reset starting product for new segment
        } else {
            int lastProduct = products.back();
            products.push_back(lastProduct * num);
        }
    }
    
    int getProduct(int k) {
        int size = products.size();
        if (k >= size) return 0;  // If k is larger than the number of products, include zero
        return products.back() / products[size - 1 - k];
    }
};
