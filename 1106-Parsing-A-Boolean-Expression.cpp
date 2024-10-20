class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> op;
        bool subExpr = 1;
        for(auto ch: expression){
            if(ch=='&' || ch=='|' || ch=='!' || ch=='t' || ch=='f')
                op.push(ch);
            else if(ch==')'){
                bool containsTrue = 0, containsFalse = 0;
                while(op.top() != '&' && op.top()!='!' && op.top()!='|'){
                    containsTrue |= op.top()=='t';
                    containsFalse |= op.top()=='f';
                    op.pop();
                }
                char operation = op.top();
                op.pop();
                if(operation=='&')
                    op.push(containsFalse ? 'f' : 't');
                if(operation=='|')
                    op.push(containsTrue ? 't' : 'f');
                if(operation=='!')
                    op.push(containsTrue ? 'f' : 't');
            }
        }
        return op.top()=='t';
    }
};