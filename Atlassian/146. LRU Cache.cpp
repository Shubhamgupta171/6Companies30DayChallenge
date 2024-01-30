class node{
    public:
    int key;
    int val;
    node* prev;
    node* next;
    node(int key,int val)
    {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }};
class LRUCache {
public:
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    LRUCache(int capacity) {
    cap=capacity;
    head->next=tail;
    tail->prev=head;
    }
    void addnode(node* newnode)
    {
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
       void deletenode(node* del_node) {
        node* delprev = del_node->prev;
        node* delnext = del_node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
    if(m.find(key)!=m.end())
    {
        node* resnode=m[key];
        int ans=resnode->val;
        m.erase(key); 
        deletenode(resnode);
        addnode(resnode);
        m[key]=head->next;
        return ans;}
        return -1;
    
    }
    void put(int key, int value) {
    
    if(m.find(key)!=m.end())
    {   
        node* del=m[key];
        m.erase(key);
        deletenode(del);
    }
    if(m.size()==cap)
    {
        m.erase(tail->prev->key);
        deletenode(tail->prev);
    }
    addnode(new node(key,value));
    m[key]=head->next;
    
}};
