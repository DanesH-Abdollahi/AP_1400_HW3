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
    output_ << &_node << " | " << _node.value << " | " << _node.left << " | " << _node.right;
    return output_;
}
//----------------------------------------------------------------
bool BST::Node::operator==(const Node& _node) const { return value == _node.value; }
//----------------------------------------------------------------
std::partial_ordering BST::Node::operator<=>(const Node& _node) const { return value <=> _node.value; }
//----------------------------------------------------------------
void BST::bfs(std::function<void(Node*& node)> func)
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
size_t length()
{
    size_t length {};
    this->bfs([&length](BST::Node*& node) { ++length; });
    return length;
}
//----------------------------------------------------------------