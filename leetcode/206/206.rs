
impl Solution {
    fn reverse(prev: Option<Box<ListNode>>, cur: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if let Some(mut cur) = cur {
            let next = cur.next;
            cur.next = prev;
            return Self::reverse(Some(cur), next)
        }
        return prev;
    }
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        Self::reverse(None, head)
    }
}