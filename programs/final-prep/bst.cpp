template<typename T>
class BinarySearchTree{
private:
    class BinaryNode;
public:
    BinarySearchTree(): root(nullptr){}
    BinarySearchTree(const BinarySearchTree& src): root(src.clone(src.root)){}
    ~BinarySearchTree(){ makeEmpty(root); }

private:
    struct BinaryNode{
        T x;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(): left(nullptr), right(nullptr){}
        BinaryNode(const T& data, BinaryNode* left=nullptr, BinaryNode* right=nullptr): x(data), left(left), right(right){} 
    };
    BinaryNode* root;
    void makeEmpty()
};