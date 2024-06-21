#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct BSTNode {
    string data;  // Change data type to string
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* root, string value) {
    if (root == NULL) {
        BSTNode* newNode = new BSTNode;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    queue <    BSTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BSTNode* current = q.front();
        q.pop();

        if (current->left == NULL) {
            current->left = new     BSTNode;
            current->left->data = value;
            current->left->left = NULL;
            current->left->right = NULL;
            return root;
        }
        else if (current->right == NULL) {
            current->right = new     BSTNode;
            current->right->data = value;
            current->right->left = NULL;
            current->right->right = NULL;
            return root;
        }
        else {
            q.push(current->left);
            q.push(current->right);
        }
    }

    return root;
}

void printt(const string& prefix, BSTNode* parent, bool isLeft, bool isRoot) {
    if (parent == nullptr)
        return;

    if (isRoot) {
        cout << "RT----";
    }
    else {
        cout << prefix <<
            (isLeft ? "(L)|----" : "(R)L----");
    }
    // print the value of the node
    cout << parent->data << endl;

    // enter the next tree level - left and right branch
    printt(prefix + (isLeft ? "  | " : "  "),
        parent->left, true, false);
    printt(prefix + (isLeft ? "  | " : "  "),
        parent->right, false, false);
}

void printBT(BSTNode* node) {
    printt("", node, false, true);
}

bool Equal(BSTNode* a, BSTNode* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a != nullptr && b != nullptr) {
        if (a->data == b->data) {
            return (Equal(a->left, b->left) && Equal(a->right, b->right));
        }
    }
    return false;
}

bool Same(BSTNode* a, BSTNode* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a != nullptr && b != nullptr)
    {
        return (Same(a->left, b->left) && Same(a->right, b->right));
    }
    return false;
}

bool Mirror(BSTNode* a, BSTNode* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a != nullptr && b != nullptr)
    {
        if (a->data == b->data) {
            return (Mirror(a->left, b->right) && Mirror(a->right, b->left));
        }
    }
    return false;
}

int main() {
    BSTNode* Root1 = nullptr;
    BSTNode* Root2 = nullptr;

    int choice;
    while (true)
    {
        cout << "(1: Insert, 2: Insert in 2nd tree, 3: equal, 4: same, 5: mirror, 6: print1,7: print 2): ";
        cin >> choice;
        if (choice == 1)
        {
            string value;
            cout << "Enter value: ";
            cin >> value;
            Root1 = insert(Root1, value);
        }
        if (choice == 2)
        {
            string value;
            cout << "Enter value: ";
            cin >> value;
            Root2 = insert(Root2, value);
        }
        else if (choice == 3) {
            if (Equal(Root1, Root2)) {
                cout << "equal" << endl;
            }
            else if (Equal(Root1, Root2) == false) {
                cout << "unequal" << endl;
            }
        }
        else if (choice == 4) {
            if (Same(Root1, Root2)) {
                cout << "same" << endl;
            }
            else if (Same(Root1, Root2) == false) {
                cout << "not same" << endl;
            }
        }
        else if (choice == 5) {
            if (Mirror(Root1, Root2)) {
                cout << "mirror" << endl;
            }
            else if (Mirror(Root1, Root2) == false) {
                cout << "not mirror" << endl;
            }
        }
        if (choice == 6)
        {
            printBT(Root1);
        }
        if (choice == 7)
        {
            printBT(Root2);
        }
    }
}