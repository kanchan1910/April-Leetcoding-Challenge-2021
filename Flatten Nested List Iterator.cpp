class NestedIterator {
public:
    vector<int> v;
    int l=0;
    void fun(vector<NestedInteger> &lst){
        for(auto i:lst)
        {
            if(i.isInteger()) 
            {
               v.push_back(i.getInteger());   
            }
            else 
            {
                fun(i.getList());
            }
            
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        fun(nestedList);
    }
    
    int next()
    {
        return v[l++];
    }
    
    bool hasNext()
    {
        return l<v.size();
    }
};
