class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length=nums1.size()+nums2.size();
        bool even_r_odd=!(length%2);
        int median=length/2;
        int i=0, j=0, tracker=0;
        float val=0;
        while(tracker<=median){
            int temp1=(i<nums1.size())?nums1[i]:std::numeric_limits<int>::max();
            int temp2=(j<nums2.size())?nums2[j]:std::numeric_limits<int>::max();
            if(tracker==median){
                return (even_r_odd)? (val+std::min(temp1, temp2))/2 : std::min(temp1, temp2);
            }
            if(temp1<temp2){
                i++;
                val=temp1;
            }
            else{
                val=temp2;
                j++;
            }
            tracker++;
        }
        return val;
    }
};