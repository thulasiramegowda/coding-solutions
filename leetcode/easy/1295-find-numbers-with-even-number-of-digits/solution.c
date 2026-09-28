int findNumbers(int* nums, int numsSize) {
    int answer=0;
  for(int i=0;i<numsSize;i++){
        if(nums[i]<10){
         continue;
        }
        if(nums[i]%2==0){
            for(int j=0;j<i;j++){
                if(j%2==0){
        answer++;
            }
            }
        }
    }
    return answer;
  }