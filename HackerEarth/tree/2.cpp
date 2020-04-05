#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int index;
    char value;
    struct Node *lnode;
    struct Node *rnode;
};

Node *makeNode(int index, char value)
{
    Node *node = new Node;
    node->index = index;
    node->value = value;
    node->lnode = NULL;
    node->rnode = NULL;
    return node;
}

Node *findNode(Node *root, int index)
{
    if (!root)
        return NULL;
    if (root->index == index)
        return root;
    Node *foundNode = findNode(root->rnode, index);
    if (foundNode)
        return foundNode;
    else
        return findNode(root->lnode, index);
}

void insertInTree(Node *root, pair<int, int> edge, string s)
{
    Node *tempRoot = root;
    int parent = edge.first;
    int childIndex = edge.second;
    char childValue = s[childIndex - 1];
    Node *childNode = makeNode(childIndex, childValue);
    Node *parentNode = findNode(tempRoot, parent);
    if (parentNode->lnode)
        parentNode->rnode = childNode;
    else
        parentNode->lnode = childNode;
}

int lookForCharinThatNode(Node *node, char lookingChar, int count)
{
    if (!node)
        return count;
    if (node->value == lookingChar)
        count++;
    int count1 = lookForCharinThatNode(node->lnode, lookingChar, count);
    int count2 = lookForCharinThatNode(node->rnode, lookingChar, 0);
    int result = count1 + count2;
    return result;
}

int answerTheQue(Node *root, pair<int, char> que)
{
    Node *tempRoot = root;
    Node *askedNode = findNode(tempRoot, que.first);
    int ans = lookForCharinThatNode(askedNode, que.second, 0);
    return ans;
}

int main()
{
    cout << "Hello" << endl;
    // int n, q;
    // cin >> n >> q;
    // string s;
    // cin >> s;
    // vector<pair<int, int>> edges;
    // int i;
    // for (i = 0; i < n - 1; i++)
    // {
    //     int node1, node2;
    //     cin >> node1 >> node2;
    //     edges.push_back(make_pair(node1, node2));
    // }

    // Node *root = makeNode(1, s[0]);

    // for (pair<int, int> edge : edges)
    // {
    //     insertInTree(root, edge, s);
    // }

    // for (i = 0; i < q; i++)
    // {
    //     int index;
    //     char value;
    //     cin >> index >> value;
    //     int ans = answerTheQue(root, make_pair(index, value));
    //     cout << ans << endl;
    // }
}