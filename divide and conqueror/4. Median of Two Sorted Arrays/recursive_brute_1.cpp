class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1=recursice(nums1, nums2, 0, 0);
        int length=nums1.size();
        int median=length/2;
        return (length%2==1)? nums1[median] : ((double)nums1[median]+nums1[median-1])/2;
    }

    std::vector<int> recursice(std::vector<int>& vect1,  std::vector<int>& vect2, int i, int j){
        if(vect1.begin()+i==vect1.end() || vect2.begin()+j==vect2.end()){
            return (vect1.begin()+i==vect1.end())? std::vector<int>(vect2.begin()+j, vect2.end()) : std::vector<int>(vect1.begin()+i, vect1.end());
        }
        if(*(vect1.begin()+i)<*(vect2.begin()+j)){
            i++;
            std::vector<int> temp_vect=recursice(vect1, vect2, i, j);
            temp_vect.insert(temp_vect.begin(), vect1.begin(), vect1.begin()+i);
            return std::vector<int>(temp_vect.begin()+i-1, temp_vect.end());
        }
        j++;
        std::vector<int> temp_vect=recursice(vect1, vect2, i, j);
        temp_vect.insert(temp_vect.begin(), vect2.begin(), vect2.begin()+j);
        return std::vector<int>(temp_vect.begin()+j-1, temp_vect.end());
    }
};