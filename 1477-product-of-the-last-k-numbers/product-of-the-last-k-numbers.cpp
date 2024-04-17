class ProductOfNumbers {
    vector<int>vec;
public:
    ProductOfNumbers() {
        // vec.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            vec.clear();
            // vec.push_back(1);
        }
        else{
            if(vec.size()==0)vec.push_back(1);
            int last=vec.back();
            vec.push_back(last*num);
        }
    }
    
    int getProduct(int k) {
        int n=vec.size();
        if(k>=n)return 0;
        return vec.back()/vec[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */