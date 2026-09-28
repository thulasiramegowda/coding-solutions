int findNumbers(int* nums, int numsSize) {
    int answer=0;
  for(int i=0;i<numsSize;i++){
    int digit=0;
    while(nums[i] != 0){
        nums[i]=nums[i]/10;
        digit++;
    }
    if(digit%2==0){
        answer++;
    }
    }
    return answer;
  }