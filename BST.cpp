#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll val;
    struct node *left;
    struct node *right;
};
void insert(struct node** root, ll val){
    if(*root == NULL){
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->val = val;
    }
    else if( (*root)->val > val)
        insert( &(*root)->left, val);
    else
        insert( &(*root)->right, val);
}
struct node *find(struct node *ptr, ll key){
    if(ptr){
        if(ptr->val == key)
            return ptr;
        else if(ptr->val > key)
            return find(ptr->left, key);
        else
            return find(ptr->right, key);   
    }
    else return NULL;
}
void preorder(struct node *ptr){
    if(ptr){
        cout<<ptr->val<<endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
int main()
{
    ll n, x;
    cin>>n;
    struct node *root = NULL,*ptr;
    for(ll i = 0; i < n; i++){
        cin>>x;
        insert(&root, x);
    }
    cin>>x;
    ptr = find(root,x);
    preorder(ptr);
}
/*
4
2 1 3 4
3
*/
