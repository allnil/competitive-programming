const int ZERO = [](){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string reverseWords(string s) {
       stack<char> rStack;
       string ans; string word;
       for(auto& c : s){
           if(c == ' '){
               while(rStack.empty() == false){
                   char ch = rStack.top(); rStack.pop();
                   word.push_back(ch);
               }
               if(word != ""){
                   if(ans != ""){
                       ans.push_back(' ');
                   }
                   ans += word;
                   word = "";
               }
               continue;
           }
           rStack.push(c);
       } 
       while(rStack.empty() == false){
           char ch = rStack.top(); rStack.pop();
           word.push_back(ch);
        }
        if(word != ""){
          if(ans != ""){
             ans += " ";
           }
         ans += word;
        }
    
       return ans;
    }
};