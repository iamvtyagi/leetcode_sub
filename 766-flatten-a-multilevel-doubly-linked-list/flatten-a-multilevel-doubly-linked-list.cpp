class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;

        while(temp){

            if(temp->child){

                Node* node = temp->next;

                Node* childHead = flatten(temp->child);

                temp->next = childHead;
                childHead->prev = temp;
                temp->child = NULL;

                Node* tail = childHead;
                while(tail->next){
                    tail = tail->next;
                }

                if(node){
                    node->prev = tail;
                }
                tail->next = node;
            }

            temp = temp->next;
        }
        return head;
    }
};