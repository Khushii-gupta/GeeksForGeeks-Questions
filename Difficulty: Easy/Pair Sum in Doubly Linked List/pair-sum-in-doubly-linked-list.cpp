/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        vector<vector<int>> ans;
        if(head == NULL) return ans;
        Node* right = head;
        while(right -> next != NULL){
            right = right -> next;
        }
        Node* left = head;
        while(left != right && left -> prev != right){
            int sum = left->data + right -> data;
            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left -> next;
                right = right -> prev;
            }
            else if(sum < target){
                left = left -> next;
            }
            else{
                right = right -> prev;
            }
        }
        return ans;
    }
};