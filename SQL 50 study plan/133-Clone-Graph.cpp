class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp){
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors){
                if(mp.find(it)!=mp.end())
                    neighbour.push_back(mp[it]);
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(!node) return node;
        if(node->neighbors.empty()){
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};