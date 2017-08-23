#include<bits/stdc++.h>
using namespace std;
int m=INT_MIN; 
struct node{
    int val;
    int lh, rh;
    struct node *left;
    struct node *right;
};
struct node *getNode(int val){
    struct node *temp = (node*)malloc(sizeof(struct node));
    temp->val = val;
    return temp;
} 
int query(struct node *ptr){
    if(ptr==NULL)return 0;//Base Condition
    else{
        ptr->lh = query(ptr->left);
        ptr->rh = query(ptr->right);
        if (ptr->lh + ptr->rh + 1  > m)
            m = ptr->lh + ptr->rh + 1;
        return ( ptr->lh > ptr->rh ? ptr->lh : ptr->rh) + 1;
    }
}
int main()
{
    struct node *root = NULL,*ptr;
    int n, x, i ;
    cin>>n>>x;
    root = getNode(x);
    string str;
    while(--n){
        cin>>str;
        i = 0;
        ptr = root;
        while(str[i] && ptr ){
            if(str[i] == 'L'){
                if(ptr->left == NULL)
                    ptr->left = getNode(0);
                ptr = ptr->left;
            }
            else{
                if(ptr->right == NULL)
                    ptr->right = getNode(0);
                ptr = ptr->right;
            }
            i++;
        }
        cin>>x;
        ptr->val = x;
    }
    query(root);
    cout<<m;
}
/*
Sample I/P
5 1
L
2
R
3
LL
4
LR
5
*/
