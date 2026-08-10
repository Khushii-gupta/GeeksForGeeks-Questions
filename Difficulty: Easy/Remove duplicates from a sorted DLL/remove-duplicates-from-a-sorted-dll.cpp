/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if (headRef == NULL)
            return NULL;

        Node* curr = headRef;

        while (curr != NULL && curr->next != NULL) {

            if (curr->data == curr->next->data) {
                Node* duplicate = curr->next;

                curr->next = duplicate->next;

                if (duplicate->next != NULL) {
                    duplicate->next->prev = curr;
                }

                delete duplicate;
            }
            else {
                curr = curr->next;
            }
        }
        return headRef;
    }
};