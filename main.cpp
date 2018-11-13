#include <iostream>
#include <cmath>
struct Node {
     int data;
     Node* left, right;
     Node(int data) {
          this->data = data;
          this->left = nullptr;
          this->right = nullptr;
     }
};

class BSTree {
     private Node *root;
     public:
          BSTree(){
               Node* root = nullptr;
          }
          BSTree(char *filename) {

          }
          ~BSTree();
          void printTree() {
               int height = height(root);
               for(int i = 1; i<= height; i++) {
                    printLeveL(i);
               }
          }
          void insertValue(int value) {
               Node* temp = new Node(0);
               temp = root;
               while(temp != nullptr) {
                    if(value < temp-> data) temp = temp->left;
                    else temp = temp-> right;
               }
               temp = new Node(value);
          }
          int height(Node* temp) {
               if(temp == nullptr) return 1;
               return std::max(height(temp->left) +1, height(temp->right) +1);
          }
          void printLeveL(int level, Node* temp) {
               if(level == 1) std::cout << temp->data << std::endl;
               else {
                    printLevel(--level, temp->left);
                    printLeveL(--level, temp->right);
               }
          }
          Node* searchValue(int value) {
               Node* temp = root;
               while(temp-> data != value) {
                    if(temp -> data < value) temp = temp->right;
                    else if(temp -> data > value) temp = temp->left;
               }
          }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
