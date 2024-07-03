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


