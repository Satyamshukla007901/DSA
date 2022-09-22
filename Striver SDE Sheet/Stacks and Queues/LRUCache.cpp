//https://leetcode.com/problems/lru-cache/submissions/
class LRUCache {
public:
    class Node
    {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int x,int y)
        {
            key = x;
            val = y;
            next = NULL;
            prev = NULL;
        }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size = 0;
    unordered_map<int,Node*> ump;
    LRUCache(int capacity) {
        
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void deleteNode(Node* node)
    {
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    int get(int key) {
        if(ump.find(key)!=ump.end())
        {
            int ans = ump[key]->val;
            deleteNode(ump[key]);
            Node* ok = new Node(key,ans);
            addNode(ok);
            ump[key] = ok;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
  void put(int key_, int value) {
      
      
      if(ump.find(key_)==ump.end())
      {
          if(ump.size()==size)
          {
                ump.erase(tail->prev->key);
                deleteNode(tail->prev);
                addNode(new Node(key_,value));
                ump[key_] = head->next;
          }
          else
          {
                addNode(new Node(key_,value));
                ump[key_] = head->next;
          }
          
          return;
      }
      deleteNode(ump[key_]);
      addNode(new Node(key_,value));
      ump[key_] = head->next;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */