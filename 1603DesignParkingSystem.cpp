class Slots{
    private:
        int numbers = 0;
    public:
        Slots(){}
        Slots(int a): numbers(a){};
        bool add_car(){
            numbers--;
            if (numbers<0){
                numbers++;
                return false;
            }
            return true;
        }
};
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        // int total_slots = big + medium + small;
        slot_vec.push_back(Slots(big));
        slot_vec.push_back(Slots(medium));
        slot_vec.push_back(Slots(small));
    }
    
    bool addCar(int carType) {
        return  slot_vec[carType-1].add_car();
    }
private:
    vector<Slots> slot_vec;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
