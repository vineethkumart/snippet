/* 
Fucntional Req
1. Parking Lot -> Parking Floor -> Spots -> Types of Spots
2. Should be able to add floors, spots, modify spots etc.,
3. User should be allowed to enter from entrances, bool slot for them calculate the fee
3. User pays and leaves
4. User can reserve in advance
5. Payment mode
6. extend  
*/
class ParkingLot {

private:
    int numfloors;
    string name;
    string location;
    capacity_info;
};

class ParkingFloor {

private:
    capacityinfo,
    reservationstatus
    free slots etc.,
};

// single spot
class ParkingSpot {
public:
    assignVehicle(int vehicle_id);
    removeVechicle();
private:
    location_idx;
    bool booked
    type; // s,m,l
    assigned_vehicle;

};

class Vehicle {

private:
    vehicle_id;
    vehicle info;
    type;
    ticket_id; // for calculating fee
};

class Reservation {
public:
    BookASpot(int vehicle_id, time duration) {
        // FInd the spot based on availability
        ParkingSpot p = find();
        p.assignVehicle(vehicle_id);
        CalcuateFee(p, duration);
        
        // assign new ticket
        return netTicket(p, vehicle_id);
    }
};