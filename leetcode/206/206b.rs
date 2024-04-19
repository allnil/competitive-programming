
impl Solution {
    pub fn reverse_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut ans:Option<Box<ListNode>> = None;
        while let Some(mut node) = head {
            head = node.next;
            node.next = ans;
            ans = Some(node);
        }
        ans
    }
}