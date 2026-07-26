/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        int pos = 1;
        Node *curr = head;
        while(curr != NULL){
            if(curr -> data == key){
                return pos;
            }
            else{
                pos++;
                curr = curr->next;
            }
        }
        return false;
    }
};
