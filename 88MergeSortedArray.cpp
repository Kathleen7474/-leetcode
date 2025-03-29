class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_i = m-1, n_i = n-1;
        int cur = m+n-1;
        while(m_i>=0&&n_i>=0){
            if(nums1[m_i]>=nums2[n_i]){
                nums1[cur] = nums1[m_i];
                cur--;
                m_i--;
            }
            else{
                nums1[cur] = nums2[n_i];
                cur--;
                n_i--;
            }
        }
        while(n_i>=0){
            nums1[cur] = nums2[n_i];
            cur--;
            n_i--;
        }
    }
};
