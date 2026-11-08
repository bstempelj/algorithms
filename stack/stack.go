package main

import "errors"

type Stack struct {
	data [50]int
	top  int
}

func (s *Stack) Top() int {
	return s.data[s.top-1]
}

func (s *Stack) Empty() bool {
	return s.top == 0
}

func (s *Stack) Full() bool {
	return s.top == len(s.data)
}

func (s *Stack) Push(x int) (int, error) {
	if s.Full() {
		return x, errors.New("stack is at max capacity")
	}
	s.data[s.top] = x
	s.top++
	return x, nil
}

func (s *Stack) Pop() (int, error) {
	if s.Empty() {
		return 0, errors.New("stack is empty")
	}
	s.top--
	x := s.data[s.top]
	return x, nil
}
