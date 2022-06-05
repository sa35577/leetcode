/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var dict = {};
    var done = false;
    nums.forEach((item) => {
        if (!dict[item]) dict[item] = 'y';
        else {
            console.log("asdf");
            done = true;
        }
        
    })
    return done;
};