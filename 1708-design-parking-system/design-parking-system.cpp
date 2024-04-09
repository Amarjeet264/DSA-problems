class ParkingSystem {
    int one=0;
    int two=0;
    int three=0;
public:
    ParkingSystem(int big, int medium, int small) {
        one=big;
        two=medium;
        three=small;
    }
    
    bool addCar(int car) {
        if(car==1){
            if(one==0){
                return false;
            }
            else{
                one-=1;
                return true;
            }
        }
        else if(car==2){
            if(two==0){
                return false;
            }
            else{
                two-=1;
                return true;
            }
        }
        else{
            if(three==0){
                return false;
            }
            else{
                three-=1;
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */