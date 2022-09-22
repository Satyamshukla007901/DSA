struct Node
{
    int key,value,cnt;
    Node* next;
    Node* prev;
    Node(int _key,int _value)
    {
        key = _key;
        value=_value;
        cnt=1;
    }
};
struct List
{
    int size;
    Node* head;
    Node* tail;
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};
class LFUCache {
    map<int,Node*> mp;
    map<int,List*> fList;
    int maxi;
    int mini;
    int curr;
public:
    LFUCache(int capacity) {
        maxi = capacity;
        mini = 0;
        curr = 0;
    }
    void update(Node* node)
    {
        
        fList[node->cnt]->removeNode(node);
        if(mini == node->cnt and fList[node->cnt]->size==0)
        {
            mini++;
        }
        List* ok = new List();
        if(fList.find(node->cnt+1)!=fList.end()) ok = fList[node->cnt+1];
        
        node->cnt++;
        ok->addFront(node);
        fList[node->cnt] = ok;
        
        
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            int val = mp[key]->value;
            update(mp[key]);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxi==0) return;
        
        if(mp.find(key)!=mp.end())
        {
            mp[key]->value = value;
            update(mp[key]);
        }
        else
        {
            if(curr==maxi)
            {
                List* list = fList[mini];
                mp.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curr--;
            }
            curr++;
            mini = 1;
            List* list = new List();
            if(fList.find(mini)!=fList.end())
            {
                list = fList[mini];
            }
            Node* node = new Node(key,value);
            list->addFront(node);
            mp[key] = node;
            fList[mini] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */