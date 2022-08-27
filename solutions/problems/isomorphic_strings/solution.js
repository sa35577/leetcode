/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    var isomorphism = {};
    var isomorphismBack = {};
    for (let i = 0; i < s.length; i++) {
        if (s[i] in isomorphism) {
            if (t[i] != isomorphism[s[i]]) return false;
        }
        else if (t[i] in isomorphismBack) return false;
        else {
            isomorphism[s[i]] = t[i];
            isomorphismBack[t[i]] = s[i];
        }
    }
    return true;
};