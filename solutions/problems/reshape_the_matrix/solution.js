/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(mat, r, c) {
    let oldr = mat.length, oldc = mat[0].length;
    if (oldr * oldc != r * c) return mat;
    var newMat = [];
    var curRow = [];
    for (let i = 0; i < r * c; i++) {
        if (i % c == 0 && i != 0) {
            newMat.push(curRow);
            curRow = [];
        }
        curRow.push(mat[Math.floor(i/oldc)][i % oldc]);
    }
    newMat.push(curRow);
    return newMat;
};