#include<iostream>
template <class ItemType>
struct TreeNode {
    ItemType info;
    TreeNode<ItemType> *left;
    TreeNode<ItemType> *right;
};
template <class ItemType>
void Insert(TreeNode<ItemType> *&tree, ItemType item){
    if(tree == NULL){
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if(item < tree->info){
        Insert(tree->left, item);
    }
    else{
        Insert(tree->right, item);
    }
}
template <class ItemType>
void PrintTree(TreeNode<ItemType> *tree){
    if(tree != NULL){
        PrintTree(tree->left);
        std::cout << tree->info << std::endl;
        PrintTree(tree->right);
    }
}
template <class ItemType>
void GetPredecessor(TreeNode<ItemType> *tree, ItemType &data){
    while(tree->right != NULL){
        tree = tree->right;
    }
    data = tree->info;
}
template <class ItemType>
void DeleteNode(TreeNode<ItemType> *&tree){
    ItemType data;
    TreeNode<ItemType> *tempPtr;
    tempPtr = tree;
    if(tree->left == NULL){
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL){
        tree = tree->left;
        delete tempPtr;
    }
    else{
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}

template <class ItemType>
void Delete(TreeNode<ItemType> *&tree, ItemType item){
    if(item < tree->info){
        Delete(tree->left, item);
    }
    else if(item > tree->info){
        Delete(tree->right, item);
    }
    else{
        DeleteNode(tree);
    }
}
template <class ItemType>
void Destroy(TreeNode<ItemType> *&tree){
    if(tree != NULL){
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}
template <class ItemType>
void Preorder(TreeNode<ItemType> *tree){
    if(tree != NULL){
        std::cout << tree->info << std::endl;
        Preorder(tree->left);
        Preorder(tree->right);
    }
}
template <class ItemType>
void Postorder(TreeNode<ItemType> *tree){
    if(tree != NULL){
        Postorder(tree->left);
        Postorder(tree->right);
        std::cout << tree->info << std::endl;
    }
}
template <class ItemType>
void Inorder(TreeNode<ItemType> *tree){
    if(tree != NULL){
        Inorder(tree->left);
        std::cout << tree->info << std::endl;
        Inorder(tree->right);
    }
}
template <class ItemType>
class TreeType{
    public:
        TreeType(){
            root = NULL;
        }
        ~TreeType(){
            Destroy(root);
        }
        
        // bool IsEmpty();

        // bool IsFull();
        // int GetLength();
        // ItemType GetItem(ItemType item, bool &found);
        void PutItem(ItemType item){
            Insert(root, item);
        }
        void DeleteItem(ItemType item){
            Delete(root, item);
        }

        void Print(){
            PrintTree(root);
        }
        void InorderTraversal(){
            Inorder(root);
        }
    private:
        TreeNode<ItemType> *root;
};
int main(){
    TreeType<int> tree;
    tree.PutItem(5);
    tree.PutItem(3);
    tree.PutItem(4);
    tree.PutItem(2);
    tree.Print();
    return 0;
}