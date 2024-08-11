#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void create(node*& root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    if(data == -1){
        root = NULL;
        return;
    }
    root = new node(data);
    create(root->left);
    create(root->right);
}
void levelordertraversal(queue<node*>&q){
    while(!q.empty()){
        node* fnode = q.front();
        q.pop();
        if(fnode != NULL){
        cout<<fnode->data<<" ";
        if(fnode->left != NULL){
            q.push(fnode->left);
        }if(fnode->right != NULL){
            q.push(fnode->right);
        }}
        if(q.front() == NULL){
            q.pop();
            cout<<endl;
            if(q.front() != NULL){
                q.push(NULL);
            }
        }
    }

}
int heightofbinarytree(node*& root){
    if(root == NULL){
        return 0;
    }
    int leftAns = 1 + heightofbinarytree(root->left);
    int rightAns = 1 + heightofbinarytree(root->right);
    return max(leftAns,rightAns);
}
bool isBalancedbinarytree(node*& root){
    if(root == NULL){
        return true;
    }
    bool mainAns = abs(heightofbinarytree(root->left)- heightofbinarytree(root->right)) <= 1;
    bool leftAns = isBalancedbinarytree(root->left);
    bool rightAns = isBalancedbinarytree(root->right);
    if(leftAns && rightAns && mainAns){
        return true;
    } else{
        return false;
    }
}
node* lowestcommonAnsestor(node*& root,node*& p,node*& q){
    if(root == NULL){
        return NULL;
    }if(root == p){
        return p;
    }if(root == q){
        return q;
    }
    node* leftAns = lowestcommonAnsestor(root->left,p,q);
    node* rightAns = lowestcommonAnsestor(root->right,p,q);
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }else if(leftAns != NULL && rightAns == NULL){
        return rightAns;
    }else{
        return NULL;
    }
}
bool isPathSum(node*& root,int sum){
    if(root == NULL){
        if(sum == 0){
            return true;
        }else{
            return false;
        }
    }
    sum = sum - root->data;
    bool leftAns = isPathSum(root->left,sum);
    bool rightAns = isPathSum(rot->right,sum);
    return leftAns || rightAns;
}
void leftviewofbinarytree(node*& root,vector<int>&leftview,int lvl){
    if(root == NULL){
        return;
    }
    if(v.size() == lvl){
        v.push_back(root->data);
    }
    leftviewofbinarytree(root->left,leftview,lvl+1);
    leftviewofbinarytree(root->right,leftview,lvl+1);
}
void topview(node*& root){
    queue<node*,int> q;
    unordered_map<int,int> vis;
    q.push(make_pair(root,0));
    while(!q.empty()){
        auto fnode = q.front();
        q.pop();
        node* newNode = fnode.first;
        int lvl = fnode.second;
        if(!vis[lvl]){
            vis[lvl] = newNode->data;
        }if(newNode->left != NULL){
            q.push(make_pair(newNode->left,lvl-1));
        }if(newNode->right != NULL){
            q.push(make_pair(newNode->right,lvl+1));
        }
    }
    for(auto i:vis){
        cout<<i.second<<" ";
    }
}
void leftboundarytraversal(node*& root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        
        leftboundarytraversal(root->left);
    }else{
        leftboundarytraversal(root->right);
    }
}
void leafnodetraversal(node*& root){
    
}
void boundarytraversal(node*& root){
    if(root == NULL){
        return;
    }
}
int main(){
    node* root = NULL;
    create(root);
    cout<<"tree created"<<endl;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    levelordertraversal(q);
}
