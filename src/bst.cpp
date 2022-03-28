#include "bst.h"

//----------------------------------------------------------------
BST::Node*& BST::get_root() { return root; }
//----------------------------------------------------------------
BST::Node::Node(int _value, Node* _left, Node* _right)
    : value { _value }
    , left { _left }
    , right { _right }
{
}
//----------------------------------------------------------------
BST::Node::Node(const Node& _node)
    : value { _node.value }
    , left { _node.left }
    , right { _node.right }
{
}
//----------------------------------------------------------------
BST::Node::Node()
    : Node(0, nullptr, nullptr)
{
}
//----------------------------------------------------------------
std::ostream& operator<<(std::ostream& output_, const BST::Node& _node)
{
    output_ << std::setw(18) << std::left << &_node << " => "
            << "value:" << std::setw(8) << std::left << _node.value << "left:"
            << std::setw(18) << std::left << _node.left
            << "right:" << std::setw(18) << std::left << _node.right;
    return output_;
}
//----------------------------------------------------------------
bool BST::Node::operator==(const Node& _node) const { return value == _node.value; }
//----------------------------------------------------------------
std::partial_ordering BST::Node::operator<=>(const Node& _node) const { return value <=> _node.value; }
//----------------------------------------------------------------
void BST::bfs(std::function<void(Node*& node)> func) const
{
    std::vector<Node*> Tree;
    Tree.push_back(root);
    while (!Tree.empty()) {
        Node* node = Tree.back();
        Tree.pop_back();
        func(node);

        if (node->left)
            Tree.push_back(node->left);
        if (node->right)
            Tree.push_back(node->right);
    }
}
//----------------------------------------------------------------
bool BST::add_node(const int& _value)
{
    if (!root) {
        root = new Node(_value);
        return true;
    }
    Node* Temp { root };
    while (true) {
        if (Temp->value == _value)
            return false;

        if (Temp->value < _value) {
            if (!Temp->right) {
                Temp->right = new Node(_value);
                return true;
            }
            Temp = Temp->right;

        } else {
            if (!Temp->left) {
                Temp->left = new Node(_value);
                return true;
            }
            Temp = Temp->left;
        }
    }
}

//----------------------------------------------------------------
size_t BST::length() const
{
    size_t length {};
    this->bfs([&length](BST::Node*& node) { ++length; });
    return length;
}
//----------------------------------------------------------------
std::ostream& operator<<(std::ostream& _output, const BST& _bst)
{
    std::cout << std::string(80, '*') << std::endl;
    _bst.bfs([&_output](BST::Node*& node) { _output << *node << std::endl; });
    std::cout << "binary search tree size:" << _bst.length() << std::endl;
    std::cout << std::string(80, '*');
    return _output;
}
//----------------------------------------------------------------
BST::Node** BST::find_node(int _value)
{
    BST::Node** Temp { &root };
    while (*Temp) {
        if ((*Temp)->value == _value)
            return Temp;

        if ((*Temp)->value < _value)
            Temp = &(*Temp)->right;
        else
            Temp = &(*Temp)->left;
    }
    return nullptr;
}
//----------------------------------------------------------------
BST::Node** BST::find_parrent(int _value)
{
    BST::Node** Temp { &root };
    if ((*Temp)->value == _value)
        return Temp;

    while (*Temp) {
        if ((*Temp)->value < _value && (*Temp)->right->value == _value)
            return Temp;
        else if ((*Temp)->value > _value && (*Temp)->left->value == _value)
            return Temp;

        if ((*Temp)->value < _value)
            Temp = &(*Temp)->right;
        else
            Temp = &(*Temp)->left;
    }
    return nullptr;
}
//----------------------------------------------------------------
BST::Node** BST::find_successor(int _value)
{
    BST::Node** Temp { find_node(_value) };

    if (!(*Temp)->left)
        return Temp;
    else
        Temp = &(*Temp)->left;

    while ((*Temp)->right) {
        Temp = &(*Temp)->right;
    }
    return Temp;
}
//----------------------------------------------------------------
bool BST::delete_node(int _value)
{
    BST::Node** Temp { find_node(_value) };
    if (!(*Temp))
        return false;

    if (!&(*Temp)->left && !&(*Temp)->right) {
        if ((*find_parrent(_value))->left->value == _value)
            (*find_parrent(_value))->left = nullptr;
        else
            (*find_parrent(_value))->right = nullptr;
        return true;
    }

    else if (&(*Temp)->left == nullptr) {
        if ((*find_parrent(_value))->left->value == _value)
            (*find_parrent(_value))->left = (*Temp)->right;
        else
            (*find_parrent(_value))->right = (*Temp)->right;
        return true;
    }

    else if (&(*Temp)->right == nullptr) {
        if ((*find_parrent(_value))->left->value == _value)
            (*find_parrent(_value))->left = (*Temp)->left;
        else
            (*find_parrent(_value))->right = (*Temp)->left;
        return true;
    } else {
        BST::Node** successor { find_successor(_value) };
        (*Temp)->value = (*successor)->value;
        if ((*successor)->right)
            (*successor)->right = (*successor)->right->right;
        else
            (*successor)->right = nullptr;
        return true;
    }
}
//----------------------------------------------------------------