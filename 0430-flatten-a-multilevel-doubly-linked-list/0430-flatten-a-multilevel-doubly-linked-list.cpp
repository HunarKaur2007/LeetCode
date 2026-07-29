/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }
        dfs(head);
        return head;
    }

public:
    Node* dfs(Node* head){
        Node* curr= head;
        Node* last = head;

        while(curr != nullptr){
            Node* next = curr->next;

            if(curr->child != nullptr){
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if(next != nullptr ){
                    childTail->next = next;
                    next->prev = childTail;
                }
                last = childTail;
            }
            else{
                last = curr;
            }
            curr= next ;
        }
        return last ;
    }

};