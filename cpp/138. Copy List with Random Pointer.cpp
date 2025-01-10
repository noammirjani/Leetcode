#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//time ON space O1
 Node* copyRandomList(Node* head) {
        if (!head) return nullptr; 

        Node *p2head = head; 

        while (p2head) {
            Node* node = new Node(p2head->val); 
            node->next = p2head->next; 
            p2head->next = node;
            p2head = node->next; 
        }

        p2head = head;
        while (p2head && p2head->next) {
            if (p2head->random) 
                p2head->next->random = p2head->random->next;
            p2head = p2head->next->next; 
        }

        p2head = head;
        Node* copy = head->next; 
        while (p2head && p2head->next) {
            Node* tag = p2head->next; 
            p2head->next = tag->next;
            if (p2head->next) tag->next = p2head->next->next;
            p2head = p2head->next; 
        }
        return copy; 
    }

Node* getObj(std::unordered_map<Node*, Node*>& addresses, Node* key) {
    if (addresses.find(key) != addresses.end())
        return addresses[key];
    Node* val = new Node(key->val); 
    addresses.insert({key, val});
    return val; 
}

// time On space On 
Node* copyRandomList2(Node* head) {
    std::unordered_map<Node*, Node*> addresses; 
    Node *copy = new Node(0), *copyHelper = copy;    

    while (head) {
        Node* newNode = getObj(addresses, head);
        if (head->next) newNode->next = getObj(addresses, head->next);
        if (head->random) newNode->random = getObj(addresses, head->random); 

        copyHelper->next = newNode;
        copyHelper = copyHelper->next; 
        head = head->next; 
    }

    return copy->next; 
}