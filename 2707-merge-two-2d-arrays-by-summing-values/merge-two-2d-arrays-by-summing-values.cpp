class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        vector<vector<int>> twoD;
        while(i < nums1.size() || j < nums2.size()) {
            vector<int> oneD;
            if(i < nums1.size() && j < nums2.size()) {
                if(nums1[i][0] == nums2[j][0]) {
                    oneD.push_back(nums1[i][0]);
                    oneD.push_back(nums1[i][1] + nums2[j][1]);
                    twoD.push_back(oneD);
                    i++;
                    j++;
                }
                else if(nums1[i][0] < nums2[j][0]) {
                    twoD.push_back(nums1[i]);
                    i++;
                }
                else {
                    twoD.push_back(nums2[j]);
                    j++;
                }
            }
            else if(i < nums1.size()) {
                twoD.push_back(nums1[i]);
                i++;
            }
            else if(j < nums2.size()) {
                twoD.push_back(nums2[j]);
                j++;
            }

        }
        return twoD;
    }
};