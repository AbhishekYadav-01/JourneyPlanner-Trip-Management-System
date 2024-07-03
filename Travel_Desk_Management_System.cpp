#include<bits/stdc++.h>
using namespace std;
class Vehicle;

class Trip {
public:
    Trip(Vehicle* vehicle, std::string pick_up_location, std::string drop_location, int departure_time)
        : vehicle(vehicle), pick_up_location(pick_up_location), drop_location(drop_location), departure_time(departure_time), booked_seats(0) {}

    // Getter functions
    Vehicle* getVehicle() const {
        return vehicle;
    }

    std::string getPickUpLocation() const {
        return pick_up_location;
    }

    std::string getDropLocation() const {
        return drop_location;
    }

    int getDepartureTime() const {
        return departure_time;
    }

    int getBookedSeats() const {
        return booked_seats;
    }

    // Setter functions
    void setVehicle(Vehicle* v) {
        vehicle = v;
    }

    void setPickUpLocation(std::string location) {
        pick_up_location = location;
    }

    void setDropLocation(std::string location) {
        drop_location = location;
    }

    void setDepartureTime(int time) {
        departure_time = time;
    }

    void setBookedSeats(int seats) {
        booked_seats = seats;
    }

private:
    Vehicle* vehicle;
    std::string pick_up_location;
    std::string drop_location;
    int departure_time;
    int booked_seats;
};
class BinaryTreeNode {
public:
    BinaryTreeNode(int departuretime = 0, Trip* tripenodeptr = nullptr, BinaryTreeNode* parentptr = nullptr)
        : leftptr(nullptr), rightptr(nullptr), parentptr(parentptr), departuretime(departuretime), tripnodeptr(tripenodeptr) {}

    // Getter functions
    BinaryTreeNode* getLeftPtr() const {
        return leftptr;
    }

    BinaryTreeNode* getRightPtr() const {
        return rightptr;
    }

    BinaryTreeNode* getParentPtr() const {
        return parentptr;
    }

    int getDepartureTime() const {
        return departuretime;
    }

    Trip* getTripNodePtr() const {
        return tripnodeptr;
    }

    // Setter functions
    void setLeftPtr(BinaryTreeNode* left) {
        leftptr = left;
    }

    void setRightPtr(BinaryTreeNode* right) {
        rightptr = right;
    }

    void setParentPtr(BinaryTreeNode* parent) {
        parentptr = parent;
    }

    void setDepartureTime(int time) {
        departuretime = time;
    }

    void setTripNodePtr(Trip* trip) {
        tripnodeptr = trip;
    }

private:
    BinaryTreeNode* leftptr;
    BinaryTreeNode* rightptr;
    BinaryTreeNode* parentptr;
    int departuretime;
    Trip* tripnodeptr;
};

class TransportService {
public:
    TransportService(std::string name) : name(name), BSThead(nullptr) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    BinaryTreeNode* getBSTHead() const {
        return BSThead;
    }

    // Setter functions
    void setName(std::string service_name) {
        name = service_name;
    }

    void setBSTHead(BinaryTreeNode* node) {
        BSThead = node;
    }
    BinaryTreeNode* add(int key,BinaryTreeNode* t,BinaryTreeNode* head){
        if(head==NULL){
            return t;
        }
        if(key<head->getDepartureTime()){
            head->setLeftPtr(add(key,t,head->getLeftPtr()));
            head->getLeftPtr()->setParentPtr(head);
        }else{
           head->setRightPtr(add(key,t,head->getRightPtr()));
            head->getRightPtr()->setParentPtr(head);
        }
        return head;
    }
    void addTrip(int key, Trip* trip)
    {
        // add the trip to the bst 
        BinaryTreeNode* temp=new BinaryTreeNode(key,trip);
        BSThead=add(key,temp,BSThead);
    }

private:
    std::string name;
    BinaryTreeNode* BSThead;
};



class Vehicle {
public:
    Vehicle(std::string vehicle_number, int seating_capacity)
        : vehicle_number(vehicle_number), seating_capacity(seating_capacity) {}

    // Getter functions
    std::string getVehicleNumber() const {
        return vehicle_number;
    }

    int getSeatingCapacity() const {
        return seating_capacity;
    }

    // Setter functions
    void setVehicleNumber(std::string number) {
        vehicle_number = number;
    }

    void setSeatingCapacity(int capacity) {
        seating_capacity = capacity;
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }
    vector<Trip*> getTrips(){
        return trips;
    }
private:
    std::string vehicle_number;
    int seating_capacity;
    std::vector<Trip*> trips;
};

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

class BinaryTree {
protected:
    BinaryTreeNode* root;

public:
    BinaryTree(){}
    BinaryTree(BinaryTreeNode* head) : root(head) {}
    int gh(BinaryTreeNode* root1){
        if(root1==NULL){
            return 0;
        }
        return 1+(max(gh(root1->getLeftPtr()),gh(root1->getRightPtr())));
    }
    int getHeight()  {
        // return the height of the tree
        return gh(root);
    }
    int gn(BinaryTreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+gn(root->getLeftPtr())+ gn(root->getRightPtr());
    }
    int getNumberOfNodes() {
        return gn(root);
        // return the no of nodes in the tree

    }
};
class BinarySearchTree : public BinaryTree {
public:
    BinarySearchTree(){

    }
    BinarySearchTree(BinaryTreeNode* head) {
        root=head;
    }
    BinaryTreeNode* mi(BinaryTreeNode* root){
        if(root==NULL){
            return root;
        }
        if(root->getLeftPtr()==NULL){
            return root;
        }
        return mi(root->getLeftPtr());
    }
    BinaryTreeNode* ma(BinaryTreeNode* root){
        if(root==NULL){
            return root;
        }
        if(root->getRightPtr()==NULL){
            return root;
        }
        return ma(root->getRightPtr());
    }
    void inorder(BinaryTreeNode* root){
        if (root == NULL) {
            return;
        }
        inorder(root->getLeftPtr());
        cout<<root->getDepartureTime()<<" ";
        inorder(root->getRightPtr());
    }
    void pre(BinaryTreeNode* root){
        if(root==NULL){
            return;
        }
        cout<<root->getDepartureTime()<<" ";
        pre(root->getLeftPtr());
        pre(root->getRightPtr());

    }
    void inordertr(){
        inorder(root);
        cout<<endl;
        pre(root);
    }
    BinaryTreeNode* getElementWithMinimumKey() {
        return mi(root);
    }

    BinaryTreeNode* getElementWithMaximumKey() {
        return ma(root);
    }
    BinaryTreeNode* snwk(BinaryTreeNode* root,int key){
        if(root==NULL){
            return root;
        }
        if(root->getDepartureTime()==key){
            return root;
        }
        int k1=root->getDepartureTime();
        if(k1>key){
            if(root->getLeftPtr()==NULL){
                return root;
            }
            return snwk(root->getLeftPtr(),key);
        }else{
            if(root->getRightPtr()==NULL){
                return root->getParentPtr();
            }
            return snwk(root->getRightPtr(),key);
        }
    }
    BinaryTreeNode* searchNodeWithKey( int key) {
        // return this will find the node with the given key (if it exists) or find the node with the key just larger than the given key k.
        return snwk(root,key);
    }
    BinaryTreeNode* getSuccessorNode(BinaryTreeNode* node)  {
       // find the successor node of the given node
       if(node->getRightPtr()==NULL){
        return node->getParentPtr();
       }
       BinaryTreeNode* temp= node->getRightPtr();
       while(temp->getLeftPtr()!=NULL){
        temp=temp->getLeftPtr();
       }        
       return temp;

    }
    BinaryTreeNode* getSuccessorNodeByKey(int key) {
        // seach the the node with key using searchnodewitkey function then return the predecessor of the node
       BinaryTreeNode* temp=searchNodeWithKey(key);
       if(temp==NULL){
        return getElementWithMinimumKey();
       }
       if(temp->getDepartureTime()==key){
            BinaryTreeNode* n= temp->getRightPtr();
            while(n->getLeftPtr()!=NULL){
                n=n->getLeftPtr();
            }
            return n;
       }else{
            return temp;
       }
    }

    BinaryTreeNode* getPredecessorNode(BinaryTreeNode* node) {
        // return Predecessor of the node
        if(node->getLeftPtr()==NULL){
            return node->getParentPtr();
        }
        BinaryTreeNode* temp= node->getLeftPtr();
        while(temp->getRightPtr()!=NULL){
            temp=temp->getRightPtr();
        }
        return temp;
        
    }

    BinaryTreeNode* getPredecessorNodeByKey(int key) {
        // seach the the node with key using searchnodewitkey function then return the predecessor of the node
       BinaryTreeNode* temp=searchNodeWithKey(key);
       if(temp==NULL){
        return getElementWithMaximumKey();
       }
       if(temp->getDepartureTime()==key){
            BinaryTreeNode* n= temp->getLeftPtr();
            while(n->getRightPtr()!=NULL){
                n=n->getRightPtr();
            }
            return n;
       }else{
            return temp->getParentPtr();
       }
    }
};

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