function increasingTriplet(nums: number[]): boolean {
    let mn = - (1 << 31) -1;
    console.log(mn);
    
    let maxInt = mn;
    
    let mx = mn + 1;
    let mid = mn;
    
    let minInt = mx;
    let isMinInt = false, isMaxInt = true;
    let done = false;
    nums.forEach((num) => {
        if (num == minInt) {
            isMinInt = true;
            mn = minInt;
        }
        else if (num <= mn) {
            mn = num;
        }
        else if (num <= mid) {
            mid = num;
        }
        else {
            mx = num;
            done = true;
        }
    })
    
    return done;
};