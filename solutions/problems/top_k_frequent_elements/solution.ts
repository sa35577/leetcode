function topKFrequent(nums: number[], k: number): number[] {
    let dict = {}
    nums.forEach((num) => {
        if (num in dict) {
            dict[num]++;
        }
        else {
            dict[num] = 1;
        }
    })
    
    let freq = []
    
    for (let key in dict) {
        freq.push([dict[key],key])
    }
    //console.log(freq)
    freq.sort((a,b) => {
        if (a[0] < b[0]) return 1;
        else return -1;
    })
    //console.log(freq)
    let ans = []
    for (let i = 0; i < k; i++) {
        ans.push(freq[i][1])
    }
    
    return ans;
    
};