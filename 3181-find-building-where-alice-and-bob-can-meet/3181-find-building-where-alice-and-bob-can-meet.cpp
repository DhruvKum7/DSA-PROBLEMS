class Solution {
public:
    void buildsegmenttree(vector<int>& heights,int i,int l,int h,int st[]){
        if(l==h){
            st[i]=l;
            return ;
        }
        int mid = l + (h - l) / 2;
        buildsegmenttree(heights, 2*i + 1, l, mid, st);
        buildsegmenttree(heights, 2*i + 2, mid + 1, h, st);

        int leftIdx = st[2*i + 1];
        int rightIdx = st[2*i + 2];
        st[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int* constructst(vector<int>& heights,int n){
        int *segmenttree = new int[4*n];
        buildsegmenttree(heights,0,0,n-1,segmenttree);
        return segmenttree;
    }

    int query(int st[],int i,int l,int h,int sta,int end,vector<int>& heights){
        if(end < l || sta > h){
            return -1;
        }
        if(sta <= l && h <= end){
            return st[i];
        }
        int mid = l + (h - l) / 2;
        int left = query(st, 2*i + 1, l, mid, sta, end, heights);
        int right = query(st, 2*i + 2, mid + 1, h, sta, end, heights);

        if(left == -1) return right;
        if(right == -1) return left;
        return (heights[left] >= heights[right]) ? left : right;
    }

    int RMIQ(vector<int>& heights,int l,int h,int n,int st[]){
        return query(st,0,0,n-1,l,h,heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segmenttree = constructst(heights,n);
        vector<int> result;

        for(auto &q : queries){
            int first = q[0];
            int second = q[1];

            if(first == second){
                result.push_back(first);
                continue;
            }

            int min_idx = min(first, second);
            int max_idx = max(first, second);

            if(heights[min_idx] < heights[max_idx]){
                result.push_back(max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n - 1;
            int result_idx = -1;

            while(l <= r){
                int mid = l + (r - l) / 2;
                int idx = RMIQ(heights, l, mid, n, segmenttree);
                if(idx != -1 && heights[idx] > heights[min_idx]){
                    result_idx = idx;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }

            result.push_back(result_idx);
        }
        return result;
    }
};
