#include <iostream>
#include <iomanip> // For setw function
using namespace std;
template <typename T> /* File: BST.h */
class BST {
private:
struct BSTNode { // A node in a binary search tree
T data; // Node value
BSTNode* left; // Left child
BSTNode* right; // Right child
BSTNode(const T& item, BSTNode* l = NULL, BSTNode* r = NULL)
: data(item), left(l), right(r) {}
};
typedef BSTNode* BSTNodePointer;
BSTNodePointer root;
/***** Member functions that you need to implement *****/
int numInternal(BSTNodePointer node) const;
int distFromRoot(BSTNodePointer node, T v) const;
int distBetweenTwoNodes(BSTNodePointer node, T x, T y) const;
void print(BSTNodePointer node, T low, T high) const;
public:
BST() : root(NULL) {} // Empty BST when its root is NULL
~BST() { delete root; }
// Assume insert member function has been implemented.
void insert(const T& item);
int numInternal() const { return numInternal(root); }
int distFromRoot(T v) const { return distFromRoot(root, v); }
int distBetweenTwoNodes(T x, T y) const {
return distBetweenTwoNodes(root, x, y);
}
void print(T low, T high) const { print(root, low, high); }
// Assume printTree member function has been implemented.
void printTree(int indent, BSTNodePointer node) const;
void printTree() const { printTree(0, root); }
};

/* Part (a) [5 points]
* Implement the member function:
* int numInternal(BSTNodePointer node) const
* Return the number of internal nodes (i.e. nodes that have child node(s)) in the BST
* Return 0 if root is NULL or if there is only one node
* You MUST use recursion.
* ADD YOUR CODE BELOW
*/
template <typename T> // 0.5 point
int BST<T>::numInternal(BSTNodePointer node) const {
if(node == NULL || node->left == NULL && node->right == NULL) // 2 points
return 0; // 0.5 point
return 1 + numInternal(node->left) + numInternal(node->right); // 2 points
}
// Note: 1 point is deducted if there are additional lines that
// make the program run wrongly. 0.5 point is deducted with
// small syntax errors.
/* Part (b) [4 points]
* Implement the member function:
* int distFromRoot(BSTNodePointer node, T v) const
* Return the distance (i.e. the number of edges) from root to the node with value v
* (For simplicity, you may assume that the value v always exists.)
* You MUST use recursion.
* ADD YOUR CODE BELOW
*/
template <typename T> // 0.5 point
int BST<T>::distFromRoot(BSTNodePointer node, T v) const {
if(node->data == v) // 0.5 point
return 0; // 0.5 point
else if(v < node->data) // 0.5 point
return 1 + distFromRoot(node->left, v); // 1 point
else
return 1 + distFromRoot(node->right, v); // 1 point
}   

template <typename T> // 0.5 point
int BST<T>::distBetweenTwoNodes(BSTNodePointer node, T x, T y) const {
if(!node)
return 0;
if(node->data > x && node->data > y) // 1 point
return distBetweenTwoNodes(node->left, x, y); // 1 point
if(node->data < x && node->data < y) // 1 point
return distBetweenTwoNodes(node->right, x, y); // 1 point
if(node->data >= x && node->data <= y) // 1 point
return distFromRoot(node, x) + distFromRoot(node, y); // 1.5 points
}
/* Part (d) [6 points]
* Implement the member function:
* void print(BSTNodePointer node, T low, T high) const
* Output all the keys stored in the BST in descending order,
* which satisfy low <= key <= high.
* You MUST use recursion.
* ADD YOUR CODE BELOW
*/
template <typename T> // 0.5 point
void BST<T>::print(BSTNodePointer node, T low, T high) const {
if(node == NULL) // 0.5 point
return;
if(node->data>high)
    print(node->left,low,high);
if(node->data<low)
    print(node->right,low,high);
if(node->data >= low && node->data <= high) // 1 point
{
    print(node->right,low,high);
    cout<<node->data<<",";
    print(node->left,low,high);
}
}

template <typename T>
void BST<T>::insert(const T& item) {
BSTNodePointer curPtr = root, parent = NULL;
bool found = false;
// First find the element
while(!found && curPtr != NULL) {
parent = curPtr;
if(item < curPtr->data) // Descend left
curPtr = curPtr->left;
else if(curPtr->data < item) // Descend right
curPtr = curPtr->right;
else // Item found
found = true;
}
if(!found) {
curPtr = new BSTNode(item); // Construct node containing item
if(parent == NULL) // Empty tree
root = curPtr;
else if(item < parent->data) // Insert to left of parent
parent->left = curPtr;
else // Insert to right of parent
parent->right = curPtr;
}
else
cout << "Item already in the tree" << endl;
}
template <typename T>
void BST<T>::printTree(int indent, BSTNodePointer node) const {
if(!node)
return;
printTree(indent + 8, node->right);
cout << setw(indent) << " " << node->data << endl;
printTree(indent + 8, node->left);
}

int main() /* BST-test.cpp */
{
BST<int> BSTree;
cout << "Adding 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 and 14 to an empty BST";
cout << endl << endl;
BSTree.insert(15); BSTree.insert(6); BSTree.insert(18);
BSTree.insert(3); BSTree.insert(7); BSTree.insert(17);
BSTree.insert(20); BSTree.insert(2); BSTree.insert(4);
BSTree.insert(13); BSTree.insert(9); BSTree.insert(14);
cout << "Resulting BST after insertion of keys:" << endl << endl;
BSTree.printTree();
cout << endl;
cout << "All the keys between 6 and 18 (printed in descending order) are: " << endl;
BSTree.print(6, 18);
cout << endl << endl;
cout << "No of internal nodes: " << BSTree.numInternal() << endl;
cout << endl;
int dist = BSTree.distBetweenTwoNodes(14, 15);
cout << "Distance between 14 and 15 is " << dist << endl;
dist = BSTree.distBetweenTwoNodes(7, 17);
cout << "Distance between 7 and 17 is " << dist << endl;
dist = BSTree.distBetweenTwoNodes(14, 18);
cout << "Distance between 14 and 18 is " << dist << endl;
dist = BSTree.distBetweenTwoNodes(2, 20);
cout << "Distance between 2 and 20 is " << dist << endl;
dist = BSTree.distBetweenTwoNodes(2, 14);
cout << "Distance between 2 and 14 is " << dist << endl;
dist = BSTree.distBetweenTwoNodes(17, 18);
cout << "Distance between 17 and 18 is " << dist << endl;
return 0;
}