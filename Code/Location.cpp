class Location {
public:
    Location(std::string name) : name(name) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    TransportService* getServicePtr(std::string droplocation) const {
        for(auto i:serviceptrs){
            if(i->getName()==droplocation){
                return i;
            }
        }
        return nullptr;
    }

    // Setter functions
    void setName(std::string location_name) {
        name = location_name;
    }

    void setServicePtr(std::string droplocation) {
        TransportService* t1=new TransportService(droplocation);
        serviceptrs.push_back(t1);
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
        TransportService* serviceptr=NULL;
        for(auto i: serviceptrs){
            if(i->getName()==trip->getDropLocation()){
                serviceptr=i;
                break;
            }
        }
        if(serviceptr==NULL){
            setServicePtr(trip->getDropLocation());
            serviceptr=getServicePtr(trip->getDropLocation());
        }
        serviceptr->addTrip(trip->getDepartureTime(),trip);
    }
    vector<Trip*> gettrips(){
        return trips;
    }
private:
    std::string name;
    std::vector<TransportService* >serviceptrs;
    std::vector<Trip*> trips;
};
