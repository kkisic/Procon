class BinaryTrie{
    struct node{
        int d, l, r;
        node(int d) : d(d) {
            l = r = -1;
        }
    };

    public:
        vector<node> nodes;

        BinaryTrie(){
            nodes.push_back(node(0));
        }

        void add(string& s, int id){
            while(SZ(s) > nodes[id].d){
                if(s[nodes[id].d] == '0'){
                    if(nodes[id].l == -1){
                        nodes[id].l = SZ(nodes);
                        nodes.push_back(node(nodes[id].d + 1));
                    }
                    id = nodes[id].l;
                }else{
                    if(nodes[id].r == -1){
                        nodes[id].r = SZ(nodes);
                        nodes.push_back(node(nodes[id].d + 1));
                    }
                    id = nodes[id].r;
                }
            }
        }
};
