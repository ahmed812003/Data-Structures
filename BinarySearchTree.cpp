#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

struct Tree {
    int size;
    int depth;
    TreeNode* root;
};

void CreateTree (Tree& t) {
    t.root = NULL;
    t.size = 0;
    t.depth = 0;
}

void InsertTree (Tree &t , int val) {
    TreeNode* prev , *curr , *p;
    int d = 1;
    p = (TreeNode*)malloc(sizeof(TreeNode));
    p->value = val; p->left = NULL ; p->right = NULL;
    if (!t.root)
        t.root = p;
    else {
        curr = t.root;
        while (curr) {
            prev = curr;
            if (val >= curr->value) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
            d++;
        }
        if (val >= prev->value) {
            prev->right = p;
        }
        else {
            prev->left = p;
        }
    }
    t.size++;
    if (t.depth < d)
        t.depth = d;
}
void DeleteNode (TreeNode* &p) {
    TreeNode* q = p , *r;
    if (!p->left) {
        p = p->right;
    }
    else if (!p->right) {
        p = p->left;
    }
    else {
        q = p->left;
        if (!q->right) {
            p->value = q->value;
            p->left = q->left;
        }
        else {
            do {
                r = q;
                q = q->right;
            } while (q->right);
            p->value = q->value;
            r->right = q->left;
        }
    }
    free(q);
}

int FindDepth (TreeNode *p) {
    if (!p) {
        return 0;
    }
    return 1 + max(FindDepth(p->left) , FindDepth(p->right));
}

int DeleteItem (Tree &t , int value) {
    int found = 0; TreeNode* pt = t.root , *r = NULL;
    while (pt) {
        if (pt->value == value) {
            found = 1;
            break;
        }
        r = pt;
        if (value < pt->value) {
            pt = pt->left;
        }
        else {
            pt = pt->right;
        }
    }
    if (found) {
        TreeNode *p;
        if (!r) {
            DeleteNode(t.root);
        }
        else if (value < r->value) {
            DeleteNode(r->left);
        }
        else {
            DeleteNode(r->right);
        }
        int d = FindDepth(t.root);
        t.depth = max(d, t.depth);
        t.size--;
    }
    return found;
}

int TreeEmpty (Tree &t) {
    return (!t.root);
}

int TreeFull (Tree &t) {
    return 0;
}

int TreeSize (Tree &t) {
    return t.size;
}

int TreeDepth (Tree &t) {
    return t.depth;
}

void PreorderRec (TreeNode* p) {
    if (p) {
        cout << p->value << " ";
        PreorderRec(p->left);
        PreorderRec(p->right);
    }
}
void Preorder (Tree &t) {
    PreorderRec(t.root);
    cout << "\n";
}

void InoederRec(TreeNode* p) {
    if (p) {
        InoederRec(p->left);
        cout << p->value << " ";
        InoederRec(p->right);
    }
}
void Inorder (Tree &t) {
    InoederRec(t.root);
    cout << "\n";
}

void PosorderRec(TreeNode* p) {
    if (p) {
        PosorderRec(p->left);
        PosorderRec(p->right);
        cout << p->value << " ";
    }
}
void Posorder (Tree &t) {
    PosorderRec(t.root);
    cout << "\n";
}

void ClearTreeRec (TreeNode* p) {
    if (p) {
        ClearTreeRec(p->left);
        ClearTreeRec(p->right);
        free(p);
    }
}
void ClearTree (Tree &t) {
    ClearTreeRec(t.root);
    t.root = NULL;
    t.size = 0;
    t.depth = 0;
}

bool FindElementFun (TreeNode *p , int &value) {
    bool found = false;
    TreeNode* pt = p;
    while (pt) {
        if (pt->value == value) {
            found = true;
            break;
        }
        else if (value < pt->value) {
            pt = pt->left;
        }
        else {
            pt = pt->right;
        }
    }
    return found;
}
void FindElement (Tree &t , int &value , bool &found) {
    found = FindElementFun(t.root , value);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Tree t;
    CreateTree(t);
    InsertTree(t, 100); InsertTree(t, 20); InsertTree(t, 200);
    InsertTree(t, 10); InsertTree(t, 30); InsertTree(t, 150);
    InsertTree(t, 300);
    Inorder(t);
    Preorder(t);
    Posorder(t);
    cout << TreeDepth(t) << "\n";
    int value = 300;
    bool x; FindElement(t , value , x);
    cout << x << "\n";
    cout << TreeSize(t) << "\n";
    int y = DeleteItem(t, 200);
    if (y) {
        Inorder(t);
    }
    cout << TreeSize(t);
    ClearTree(t);
    Inorder(t);
    cout << TreeSize(t);

    Tree t1;
    CreateTree(t1);
    InsertTree(t1, 50); InsertTree(t1, 30); InsertTree(t1, 20);
    InsertTree(t1, 40); InsertTree(t1, 70); InsertTree(t1, 60);
    InsertTree(t1, 80);
    Inorder(t1);
    int z = DeleteItem(t1 , 20);
    Inorder(t1);
    z = DeleteItem(t1 , 30);
    Inorder(t1);
    z = DeleteItem(t1 , 50);
    Inorder(t1);

    return 0;
}