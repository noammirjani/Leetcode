#include <vector>

class ParkingSystem {
private:
    std::vector<int> spots;
public:
    ParkingSystem(int big, int medium, int small) {
        spots = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if (spots[carType-1] > 0) {
            spots[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */