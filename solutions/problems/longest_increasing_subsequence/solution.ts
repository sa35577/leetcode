function bsearch(arr: number[], val: number): number {
    let L = 0, R = arr.length - 1;
    if (val >= arr[R]) return R;
    while (L < R) {
        let mid = Math.floor((L+R)/2);
        if (arr[mid] > val) R = mid;
        else if (arr[mid] < val) {
            if (arr[mid+1] >= val) return mid;
            else L = mid+1;
        }
        else return mid;
    }
    return -1;
}

function lengthOfLIS(nums: number[]): number {
    //let d = [-100,100,100,100,100,100,100];
    //console.log(bsearch(d,10))
    
    console.log('asdf');
    let dp: Array<number> = [];
    dp.push(-100000);
    if (nums.length == 1) return 1;
    for (let i = 1; i <= nums.length; i++) dp.push(100000);
    nums.forEach((val) => {
        let mid = bsearch(dp,val);
        if (mid == dp.length - 1 || mid == -1) {
            ;
        }
        else if (dp[mid] < val && dp[mid+1] > val) {
            dp[mid+1] = val;
        }
        //console.log(dp);
        //console.log(mid);
    })
    
    for (let i = dp.length - 1; i >= 0; i--) {
        if (dp[i] != 100000) return i;
    }
};