/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        // code here
        Node *temp = new Node(x);
        Node *curr = head;
        for(int i = 0; i < p; i++){
            curr = curr -> next;
        }
        temp -> next = curr -> next;
        temp -> prev = curr;
        
        if(curr -> next != NULL){
            curr -> next -> prev = temp;
        }
        curr -> next = temp;
        return head;
        
    }
};