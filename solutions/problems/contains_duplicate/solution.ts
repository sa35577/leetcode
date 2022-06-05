function containsDuplicate(nums: number[]): boolean {
    nums.sort();
    //console.log(nums);
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i-1]) return true;
    }
    return false;
};