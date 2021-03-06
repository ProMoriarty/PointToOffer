/**
*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        int left = 0,right = rotateArray.size()-1;
        int indexMid = left;
        while(rotateArray[left]>=rotateArray[right]){
            if(right-left==1){
                indexMid = right;
                break;
            }
            indexMid = left + (right-left)/2;
            if(rotateArray[indexMid]>=rotateArray[left])
                left = indexMid;
           	if(rotateArray[indexMid]<=rotateArray[right])
                right = indexMid;
        }
        return rotateArray[indexMid];
    }
};