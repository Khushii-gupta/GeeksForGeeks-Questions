/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        // code here
        head = reverseList(head);
        Node* curr = head;
        int carry = 1;
        while(curr != NULL && carry){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            if(curr -> next == NULL && carry){
                curr->next = new Node(carry);
                carry = 0;
            }
            
            curr = curr->next;
        }
        head = reverseList(head);
        return head;
    }
};