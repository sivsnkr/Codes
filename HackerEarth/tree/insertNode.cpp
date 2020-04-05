#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *lnode;
    struct Node *rnode;
};

Node *makeNode(int value)
{
    Node *node = new Node;
    node->value = value;
    node->lnode = NULL;
    node->rnode = NULL;
    return node;
}

Node *findNode(Node *root, int value)
{
    if (!root)
        return NULL;
    if (root->value == value)
        return root;
    Node *lookInLeft = NULL;
    lookInLeft = findNode(root->lnode, value);
    if (!lookInLeft)
    {
        return findNode(root->rnode, value);
    }
    return lookInLeft;
}

void insertToTree(Node *root, pair<int, int> edge)
{
    Node *tempRoot = root;
    int parent = edge.first;
    int child = edge.second;
    Node *parentNode = findNode(tempRoot, parent);
    Node *childNode = makeNode(child);
    if (parentNode->lnode)
        parentNode->rnode = childNode;
    else
        parentNode->lnode = childNode;
}

int giveMeAns(Node *root, vector<int> directoryToDelete, int count)
{
    if (!root)
        return count;
    if (find(directoryToDelete.begin(), directoryToDelete.end(), root->value) != directoryToDelete.end())
    {
        // delete this node
        return count + 1;
    }

    int leftCount = giveMeAns(root->lnode, directoryToDelete, count);
    int rightCount = giveMeAns(root->rnode, directoryToDelete, 0);
    return leftCount + rightCount;
}

int main()
{
    int n;
    cin >> n;

    Node *root = makeNode(1);

    int i;
    // zunk code
    cin >> i;

    for (i = 0; i < n - 1; i++)
    {
        int value;
        cin >> value;
        insertToTree(root, make_pair(value, i + 2));
    }

    int m;
    cin >> m;
    vector<int> directoryToDelete;
    for (i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        directoryToDelete.push_back(value);
    }

    sort(directoryToDelete.begin(), directoryToDelete.end());

    int result = giveMeAns(root, directoryToDelete, 0);
    cout << result << endl;
}