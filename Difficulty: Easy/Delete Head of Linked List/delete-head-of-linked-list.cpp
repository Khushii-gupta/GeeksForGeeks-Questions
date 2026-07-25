/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        // code here
        if(head == NULL){
            return NULL;
        }
        else{
            Node *temp = head -> next;
            delete head;
            return temp;
        }
    }
};
