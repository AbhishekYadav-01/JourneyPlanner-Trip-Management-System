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
