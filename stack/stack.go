package main

import (
	"fmt"
	"errors"
)

type Stack struct {
	data [50]int
	size int
}

func (s *Stack) Push(x int) (int, error) {
	if s.size == len(s.data) {
		return x, errors.New("stack is at max capacity")
	}
	s.data[s.size] = x; s.size++
	return x, nil
}

func (s *Stack) Pop() (int, error) {
	if s.size == 0 {
		return 0, errors.New("stack is empty")
	}
	s.size--; x := s.data[s.size]
	return x, nil
}

func main() {
	var s Stack
	for i := 0; i < 50; i++ {
		s.Push(i)
	}
	_, err := s.Push(50)
	fmt.Println(err)

	for i := 0; i < 50; i++ {
		x, _ := s.Pop()
		fmt.Printf("%d ", x)
	}
	fmt.Println()

	_, err = s.Pop()
	fmt.Println(err)

	for i := 1; i <= 50; i++ {
		s.Push(-i)
	}
	fmt.Println(s)
}
