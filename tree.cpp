#include <iostream>
#include <queue>

using namespace std;

struct node
{
    node* leftc;
    int data;
    node* rightc;

    node(int var) {
        leftc = nullptr;
        data = var;
        rightc = nullptr;
    }
};

class tree
{
private:
    node* root;
    queue<node*> q;
public:
    tree(){
        root = nullptr;
    }
    node* add() {
        node *p, *t;
        int x;

        cout << "Enter root value : - ";
        cin >> x;
        root = new node(x);
        q.push(root);

        while(!q.empty()) {
            p = q.front();
            q.pop();
            cout << "Enter left child of " << p->data <<" :- "; //If any child is null enter -1 
            cin >> x;
            if(x != -1) {
                t = new node(x);
                p->leftc = t;
                q.push(t);
            }
            cout << "Enter right child of " << p->data <<" :- ";
            cin >> x;
            if(x != -1) {
                t = new node(x);
                p->rightc = t;
                q.push(t);
            }
        }
        return root;
    }

    void preorder(node* root) {
        if(root != nullptr) {
            cout << root->data << endl;
            preorder(root->leftc);
            preorder(root->rightc);
        }
    }

     void inorder(node* root) {
        if(root != nullptr) {
            inorder(root->leftc);
            cout << root->data << endl;
            inorder(root->rightc);
        }
    }

     void postorder(node* root) {
        if(root != nullptr) {
            postorder(root->leftc);
            postorder(root->rightc);
            cout << root->data << endl;
        }
    }
};

int main()
{
    tree t;
    node* root;

    root = t.add();
    cout << "\n Preorder :- ";
    t.preorder(root);
    cout << "\n Inorder :- ";
    t.inorder(root);
    cout << "\n Postorder :- ";
    t.postorder(root);
    return 0;
}