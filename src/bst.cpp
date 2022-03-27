#include "bst.h"

//----------------------------------------------------------------
BST::Node*& BST::get_root() { return root; }
//----------------------------------------------------------------
BST::Node::Node(int value_, Node* left_, Node* right_)
    : value { value_ }
    , left { left_ }
    , right { right_ }
{
}
//----------------------------------------------------------------
BST::Node::Node(const Node& node_)
    : value { node_.value }
    , left { node_.left }
    , right { node_.right }
{
}
//----------------------------------------------------------------
BST::Node::Node()
    : Node(0, nullptr, nullptr)
{
}
//----------------------------------------------------------------