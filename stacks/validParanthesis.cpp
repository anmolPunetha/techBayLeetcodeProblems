class Solution {
public:
    bool isValid(string s) {
        stack<char>stk; //push,pop,top
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            //ch could an opening bracket/closing bracket
            if(ch=='(' or ch=='[' or ch=='{'){ //if its an opening bracket
                stk.push(ch);
            }
            else{ //closing bracket
                if(stk.empty()==true) return false;
                else{
                    if((ch==')' and stk.top()=='(') or (ch=='}' and stk.top()=='{') or (ch==']' and stk.top()=='[')){
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(stk.empty()==true)return true;
        return false;
    }
};
