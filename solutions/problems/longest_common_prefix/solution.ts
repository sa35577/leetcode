function longestCommonPrefix(strs: string[]): string {
    let x = "";
    if (strs.length == 1) return strs[0];
    let done = false;
    for (let i = 0; i < strs[0].length; i++) {
        for (let j = 1; j < strs.length; j++) {
            if (strs[j].length > i && strs[j][i] == strs[0][i]) {
                ;
            }
            else {
                done = true;
                break;
            }
        }
        if (done) break;
        x += strs[0][i];
    }
    return x;
};