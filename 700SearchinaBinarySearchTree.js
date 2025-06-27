/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    if(root==null)
        return null;
    if(root.val == val)
        return root;
    else{
        var left = searchBST(root.left, val);
        var right = searchBST(root.right, val);
        // console.log("root.val", root.val, " T or F", (root.val==val), val);
        // console.log("left.val", left, "right val", right);
        
        return (left||right);
    }
    return null;
};
