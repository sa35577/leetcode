function merge(intervals: number[][]): number[][] {
    let arr = [];
    intervals.forEach((intrvl) => {
        arr.push([intrvl[0],0]);
        arr.push([intrvl[1],1]);
    })
    //console.log(arr);
    arr.sort((a,b) => {
        if (a[0] < b[0]) return -1;
        if (a[0] > b[0]) return 1;
        if (a[1] > b[1]) return 1;
        return -1;
    });
    //console.log(arr);
    let res = [];
    let cur = [];
    let curOpen = 0;
    
    arr.forEach((pair) => {
        if (pair[1] == 0) {
            curOpen++;
            if (curOpen == 1) {
               cur.push(pair[0]); 
            }
        }
        else {
            curOpen--;
            if (curOpen == 0) {
                cur.push(pair[0]);
                res.push(cur);
                cur = [];
            }
        }
    })
    
    return res;
};