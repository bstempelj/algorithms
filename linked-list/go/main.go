package main

import "fmt"

type Node struct {
	Val int
	Next *Node
}

func (n *Node) String() string {
	return fmt.Sprintf("{%d, %p}", n.Val, n.Next)
}

func newNodeFromSlice(nums []int) *Node {
	if len(nums) == 0 {
		return nil
	}

	head := &Node{Val: nums[0]}
	node := head

	for _, n := range nums[1:] {
		node.Next = &Node{Val: n}
		node = node.Next
	}
	return head
}

func printList(head *Node) {
	fmt.Print(head)
	for head != nil {
		head = head.Next
		fmt.Printf(", %v", head)
	}
	fmt.Println()
}

func reverseList(head *Node) *Node {
	var prev *Node
	for head != nil {
		next := head.Next
		head.Next = prev 
		prev = head
		head = next
	}
	return prev
}

func isPalindrome(head *Node) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	left, right := head, reverseList(slow)

	for right != nil {
		if left.Val != right.Val {
			return false
		}
		left, right = left.Next, right.Next
	}
	return true
}

func main() {
	//head := newNodeFromSlice([]int{1,2,3,4,5})
	head := newNodeFromSlice([]int{1,2,2,1})
	fmt.Println(isPalindrome(head))
}
