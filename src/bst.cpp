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