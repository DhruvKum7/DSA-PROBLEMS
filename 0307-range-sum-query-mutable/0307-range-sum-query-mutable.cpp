class NumArray {
public:
    vector<int>segment_tree;
    int n;
    void buildtree(vector<int>& nums,int i,int l,int h){
        if(l==h){
            segment_tree[i]=nums[l];
            return;
        }
        int mid = l+(h-l)/2;
        buildtree(nums,2*i+1,l,mid);
        buildtree(nums,2*i+2,mid+1,h);

        segment_tree[i]=segment_tree[2*i+1]+segment_tree[2*i+2];
    }

    void updatequery(int index, int val,int i,int l,int h){
        if(l==h){
            segment_tree[i]=val;
            return ;
        }
        int mid = l+(h-l)/2;
        if(index<=mid){
        updatequery(index,val,2*i+1,l,mid);
        }else{
        updatequery(index,val,2*i+2,mid+1,h);
        }
        segment_tree[i]=segment_tree[2*i+1]+segment_tree[2*i+2];
    }

    int query(int i,int l,int h,int st,int end){
        if(end<l || st>h){
            return 0;
        }
        if(st<=l && end>=h){
            return segment_tree[i];
        }
        int mid=l+(h-l)/2;
        return (query(2*i+1,l,mid,st,end)+query(2*i+2,mid+1,h,st,end));
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segment_tree.resize(4*n);
        buildtree(nums,0,0,n-1);

    }
    
    void update(int index, int val) {
       updatequery(index,val,0,0,n-1); 
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */