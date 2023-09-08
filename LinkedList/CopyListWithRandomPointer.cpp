class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Create duplicate node right after its original node
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        //connecting random of duplicate nodes using the original node random
        Node* itr = head;
        while(itr){
            if(itr->random)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        //connect all deep copy linked list and separate betweem copy and original LL
        Node* dummy = new Node(-1);
        itr = head;
        temp = dummy;
        Node* front;
        while(itr){
            front = itr->next->next;
            temp->next = itr->next;
            temp = temp->next;
            itr->next = front;
            itr = front;
        }
        return dummy->next;
    }
};