/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node* curr = head;
        while(curr != NULL){
            Node* nextNode = curr -> next;
            if(curr -> data == x){
                if(curr -> prev) curr -> prev -> next = curr -> next;
                else head = curr -> next;
            if(curr -> next) curr -> next -> prev = curr -> prev;
            delete curr;
            }
            curr = nextNode;
        }
        return head;
    }
};