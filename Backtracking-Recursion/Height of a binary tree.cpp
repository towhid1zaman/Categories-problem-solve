// full code in Tree
int height(node * root){
    if(root==NULL) return 0;
    int hL=0, hR=0;
    hL = height(root->left)+1;
    hR = height(root->right)+1;
    return max(hL,hR);
}
  
