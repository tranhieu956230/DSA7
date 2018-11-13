#include <iostream>
#include <cmath>
#include <fstream>
struct Node {
     int data;
     Node* left;
     Node* right;
     Node(int data) {
          this->data = data;
          this->left = nullptr;
          this->right = nullptr;
     }
};

class BSTree {
     private:
     Node *root = nullptr;
     public:
          BSTree(){
               Node* root = nullptr;
          }
          BSTree(char *filename) {
               std::fstream file;
               file.open(filename, std::fstream::in);
               int i;
               while(file >> i) {
                    insertValue(i);
               }
          }
          ~BSTree();
          void printTree() {
               int h = height(root);
               for(int i = 1; i<= h; i++) {
                    printLeveL(i, root);
               }
          }
          void insertValue(int value) {
               if(root == nullptr) {
                    root = new Node(value);
                    return;
               }
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
                    if(temp == nullptr) break;
               }
               return temp;
          }
};
int main()
{
     BSTree bst = BSTree("bst.txt");
    cout << "Hello world!" << endl;
    return 0;
}
