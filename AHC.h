#pragma once

// #include <unordered_map>
#include <string>
#include <vector>
// #include <unordered_set>

using uint = unsigned int;
#define NYT_SYMBOL -1 // Not Yet Transmitted

struct Node
{
    char symbol;
    uint frequency;
    Node *left;
    Node *right;
    Node *parent;
    Node() : symbol(0), frequency(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(char symbol, uint frequency) : symbol(symbol), frequency(frequency), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(char symbol, uint frequency, Node *left, Node *right) : symbol(symbol), frequency(frequency), left(left), right(right), parent(nullptr) {}
    Node(char symbol, uint frequency, Node *left, Node *right, Node *parent) : symbol(symbol), frequency(frequency), left(left), right(right), parent(parent) {}
    // check if the node is a leaf node
    bool isLeaf() const { return left == nullptr && right == nullptr; }
};

class AHC
{
public:
    AHC();
    ~AHC();
    std::string encode(const std::string &input);
    std::string decode(std::string input);

private:
    void initEncodeTree();
    void initDecodeTree();
    void update(const char symbol, Node *isFind, bool isEncode = true);
    // std::string vectorBool2String(const std::vector<bool> &v);
    Node *getMaxIndexNode(Node *node, bool isEncode = true);
    void swapNode(Node *node1, Node *node2);
    // void updateCodetable(Node *node, std::vector<bool> &code);
    void deleteTree(Node *&node);
    // void printTree(Node *node, int depth = 0);
    std::string int2Roman(int num);
    // void printEscape_char(char ch, std::stringstream &ss);
    void showTree();
    Node *findSymbol(Node *node, char symbol, std::string &code);
    Node *findCode(Node *node, const std::string &code, int &depth);
    void middleOrderTree(Node *node, std::vector<std::pair<std::pair<Node *, Node *>, std::string>> &v);
    void outputTree(std::vector<std::pair<std::pair<Node *, Node *>, std::string>> &v);

private:
    Node *encode_root;
    Node *decode_root;
    Node *encode_NYT;
    Node *decode_NYT;
    // std::unordered_map<char, std::string> code_table;
    // std::unordered_map<char, std::vector<bool>> code_table;
    // std::unordered_set<char> escape_set;
};
