/*
  Given an array find all possible permutaions,
  n lengths array = n! permutaions
*/

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}
void backtracking(std::vector<int> &A, std::vector< vector<int> > &v, int l){
    if(l==A.size()-1){
        v.push_back(A);
        return;
    }
    for(int i = l; i<A.size(); i++){
        swap(A[i], A[l]);
        backtracking(A,v, l+1);
        swap(A[i], A[l]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > v;
    backtracking(A,v,0);
    sort(v.begin(),v.end());
    return v;
}
