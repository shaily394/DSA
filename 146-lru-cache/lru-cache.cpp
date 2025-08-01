class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) { 
    this->key =key;
    this->val = val;
    prev =nullptr;
    next = nullptr; }
};


class LRUCache {
public:
    int cap;
    Node* head = new Node (-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }
    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) //map returns m.end() if it does not find the key.
        {
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */