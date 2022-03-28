#ifndef BST_H
#define BST_H
#include <compare>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

class BST {
public:
    class Node {
    public:
        Node(int value, Node* left = nullptr, Node* right = nullptr);
        Node();
        Node(const Node& node);

        friend std::ostream& operator<<(std::ostream&, const BST::Node&);

        bool operator==(const Node&) const;
        std::partial_ordering operator<=>(const Node&) const;

        int value;
        Node* left;
        Node* right;
    };

    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func) const;
    size_t length() const;
    bool add_node(const int& value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

    friend std::ostream& operator<<(std::ostream&, const BST&);

private:
    Node* root;
};

#endif // BST_H