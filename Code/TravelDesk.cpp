class TravelDesk {
public:
    void addTrip(std::string vehicle_number, int seating_capacity, std::string pick_up_location, std::string drop_location, int departure_time) {
        // Implement this function to add a trip
        Vehicle* v;
        Location* loc=NULL;
        int f1=0,f2=0,f3=0;
        for(auto i: locations){
            if(i->getName()==pick_up_location){
                loc=i;
                f1=1;
                break;
            }
        }
        for(auto i:vehicles){
            if(i->getVehicleNumber()==vehicle_number){
                v=i;
                f2=1;
                break;
            }
        }
        if(f1==0){
            loc=new Location(pick_up_location);
            locations.push_back(loc);
        }
        if(f2==0){
            v=new Vehicle(vehicle_number,seating_capacity);
            vehicles.push_back(v);
        }
        Trip* trip=new Trip(v,pick_up_location,drop_location,departure_time);
        v->addTrip(trip);
        loc->addTrip(trip);
    }

    std::vector<Trip*> showTrips(std::string pick_up_location, int after_time, int before_time) {
        // Implement this function to retrieve trips within a specified time range
        vector<Trip*> ans,temp;
        Location* loc=NULL;
        for (auto i : locations){
            if(i->getName()==pick_up_location){
                loc=i;
                break;
            }
        }
        if(!loc){
            return ans;
        }
        temp=loc->gettrips();
        for(auto i:temp){
            int cur=i->getDepartureTime();
            if(cur>after_time && cur<before_time){
                ans.push_back(i);
            }
        }
        return ans; // Placeholder
    }
    std::vector<Trip*> showTripsbydestination(std::string pick_up_location, std::string destination,int after_time, int before_time) {
        // Implement this function to retrieve trips within a specified time range form pickup to droplocatin
        vector<Trip*> ans;
        Location* loc=NULL;
        for (auto i : locations){
            if(i->getName()==pick_up_location){
                loc=i;
                break;
            }
        }
        if(!loc){
            return ans;
        }
        BinaryTreeNode* head;
        TransportService* t1=loc->getServicePtr(destination);
        head=t1->getBSTHead();
        BinarySearchTree bst(head);
        BinaryTreeNode* start=bst.getSuccessorNodeByKey(after_time);
        while( start->getDepartureTime()<before_time){
            ans.push_back(start->getTripNodePtr());
            start=bst.getSuccessorNode(start);
        }
        return ans; // Placeholder
    }

    Trip* bookTrip(std::string pick_up_location, std::string drop_location, std::string vehicle_number, int departure_time) {
        // Implement this function to book a trip
        Location* loc=NULL;
        Vehicle *v = NULL;
        TransportService* t1;
        for(auto i: locations){
            if(i->getName()==pick_up_location){
                loc=i;
                t1=i->getServicePtr(drop_location);
                break;
            }
        }
        if(t1==NULL){
            return NULL;
        }
        for(auto i: vehicles){
            if(i->getVehicleNumber()==vehicle_number){
                v=i;
                break;
            }
        }
        BinaryTreeNode* head=t1->getBSTHead();
        BinaryTreeNode* cur=head;
        while( departure_time!=cur->getDepartureTime()){
            if(departure_time<cur->getDepartureTime()){
                cur=cur->getLeftPtr();
            }else{
                cur=cur->getRightPtr();
            }
        }
        Trip* ans=cur->getTripNodePtr();
        if(ans->getDropLocation()!=drop_location){
            return NULL;
        }
        ans->setBookedSeats(ans->getBookedSeats()+1);
        return ans; // Placeholder
    }
    Location* getLocation(std::string location){
        for(auto i:locations){
            if(i->getName()==location){
                return i;
            }
        }
        return nullptr;
    }

private:
    std::vector<Vehicle*> vehicles;
    std::vector<Location*> locations;
};
