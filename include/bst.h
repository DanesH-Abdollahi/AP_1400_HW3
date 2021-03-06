#ifndef BST_H
#define BST_H
#include <compare>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

class BST {
public:
    class Node {
    public:
        Node(int value, Node* left = nullptr, Node* right = nullptr);
        Node(); // Default Constructor
        Node(const Node& node); // Copy Cunstructor

        bool operator==(const Node&) const;
        std::partial_ordering operator<=>(const Node&) const;
        friend std::ostream& operator<<(std::ostream&, const BST::Node&);

        int value;
        Node* left;
        Node* right;
    };

    BST(); // Default Constructor
    BST(const BST& bst); // Copy Cunstructor
    ~BST(); // Destructor
    BST(BST&& source); // Move Constructor
    BST(std::initializer_list<int>); // Initializer List Constructor
    BST& operator=(const BST&); // Copy Version
    BST& operator=(BST&&); // Move Version

    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func) const;
    size_t length() const;
    bool add_node(const int& value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

    const BST& operator++() const; // Left ++
    const BST operator++(int) const; // Right ++
    friend std::ostream& operator<<(std::ostream&, const BST&);

private:
    Node* root;
};

#endif // BST_H