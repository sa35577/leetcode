/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let L = 0, R = matrix[0].length - 1;
    let U = 0, D = matrix.length - 1;
    let cnt = 0;
    let dir = "R";
    let res = [];
    let y = 0, x = 0;
    while (cnt < matrix.length * matrix[0].length) {
        if (dir == "R") {
            res.push(matrix[y][x]);
            cnt++;
            if (x == R) {
                y++; U++;
                dir = "D";
            }
            else x++;
        }
        else if (dir == "D") {
            res.push(matrix[y][x]);
            cnt++;
            if (y == D) {
                x--; R--;
                dir = "L";
            }
            else y++;
        }
        else if (dir == "L") {
            res.push(matrix[y][x]);
            cnt++;
            if (x == L) {
                y--; D--;
                dir = "U";
            }
            else x--;
        }
        else if (dir == "U") {
            res.push(matrix[y][x]);
            cnt++;
            if (y == U) {
                x++; L++;
                dir = "R";
            }
            else y--;
        }
    }
    return res;
};