/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:

    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    Node* flatten(Node* head) {

        if (head == NULL)
            return NULL;

        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Har vertical list ka first node heap me daalo
        Node* temp = head;

        while (temp != NULL) {
            pq.push(temp);
            temp = temp->next;
        }

        Node* dummy = new Node(-1);
        Node* curr = dummy;

        while (!pq.empty()) {

            Node* node = pq.top();
            pq.pop();

            // Current node ko answer me add karo
            curr->bottom = node;
            curr = node;

            // Is node ki next vertical value ko heap me daalo
            if (node->bottom != NULL) {
                pq.push(node->bottom);
            }

            // next pointer ko remove karo
            curr->next = NULL;
        }

        return dummy->bottom;
    }
};