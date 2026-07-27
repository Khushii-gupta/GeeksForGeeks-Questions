/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if (x == 1) {
            Node* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp;
            return head;
        }

        Node* curr = head;
        for (int i = 1; i < x; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        delete curr;

        return head;
    }
};