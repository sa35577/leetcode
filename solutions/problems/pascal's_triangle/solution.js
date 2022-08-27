/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let res = [[1]];
    for (let i = 1; i < numRows; i++) {
        let curRow = [1];
        for (let j = 0; j < i-1; j++) curRow.push(res[i-1][j] + res[i-1][j+1]);
        curRow.push(1);
        res.push(curRow);
    }
    return res;
};