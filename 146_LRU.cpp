class node{
public:
    int key, val;
    node* next;
    node* prev;
    node(int _key, int _val){
        key=_key;
        val=_val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, node*>mp;  //key=key of lru, val=node of DLL
    node* head=new node(-1, -1);
    node* tail=new node(-1, -1);
    int size;
    LRUCache(int capacity) {
        size=capacity;
        //setting the links of dummy pointers here
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node* temp){
        node*nxt = head->next;
        //making the front connection
        head->next=temp;
        temp->prev=head;

        //connection part 2
        nxt->prev=temp;
        temp->next=nxt;
    }

    void deleteNode(node* temp){
        node*temp_next=temp->next;
        node*temp_prev=temp->prev;

        temp_prev->next=temp_next;
        temp_next->prev=temp_prev;
    }

    int get(int key) {
        //i will have this key/not
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int ansVal = mp[key]->val;
        deleteNode(mp[key]); //delete this particular node==>DLL
        mp.erase(key);  //deleting from the map as well

        node* temp=new node(key, ansVal);
        addNode(temp);  //this would add at the front
        mp[key]=temp;

        return ansVal;
    }
    
    void put(int key, int value) {
        //already that key is there
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }

        //if it is not there->2cases->cap reached/not
        if(mp.size()==size){
            //remove->lru
            mp.erase(tail->prev->key);
            deleteNode(tail->prev); //this is my lru
        }

        //adding 
        node* temp = new node(key,value);
        addNode(temp);
        mp[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 
