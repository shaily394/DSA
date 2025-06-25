class Node{
    public:
        int key;
        int val;
        int cnt;
        Node*prev = NULL;
        Node*next = NULL;
        Node(int key_, int val_){
            key = key_;
            val = val_;
            cnt = 1;
            prev=next=nullptr;
        }
    };

class List{
    public:
        int size;
        Node*head;
        Node*tail;
        List(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
         void addFront(Node* node){
            Node*temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }
        void removeNode(Node* del){
            Node* delprev = del->prev;
            Node* delnext = del->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };


class LFUCache {
public:
    unordered_map<int , Node*>keyNode;
    unordered_map<int , List*>freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;

    }
    
    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        node->cnt += 1;

        List* nextHigherFreqList;
        if (freqListMap.find(node->cnt) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt];
        } else {
            nextHigherFreqList = new List();
        }

        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        int val = node->val;
        updateFreqListMap(node);
        return val;

    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;
                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                curSize--;
            }

            curSize++;
            minFreq = 1;
            Node* newNode = new Node(key, value);

            List* listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
            }
            listFreq->addFront(newNode);
            freqListMap[minFreq] = listFreq;
            keyNode[key] = newNode;



    }
}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */