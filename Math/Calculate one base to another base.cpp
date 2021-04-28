int charVal(char c){
  if(c<='9' and c>='0')return c - '0';
  else return c - 'A' + 10;
}
ll Base(string s, int n, int base){
    ll b = 0;
    for(int i = 0; i<n ; i++){
      b*=base;
      b+=charVal(s[i]);
    }
    return b;
}
