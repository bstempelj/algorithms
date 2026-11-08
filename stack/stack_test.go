package main

import "testing"

func TestStack(t *testing.T) {
	t.Run("push one element", func(t *testing.T) {
		var s Stack
		s.Push(1)
		if s.Top() != 1 {
			t.Errorf("expected 1, got %d\n", s.Top())
		}
	})

	t.Run("push multiple elements", func(t *testing.T) {
		var s Stack
		s.Push(1)
		s.Push(2)
		s.Push(3)
		if s.Top() != 3 {
			t.Errorf("expected 1, got %d\n", s.Top())
		}
	})

	t.Run("push one then pop", func(t *testing.T) {
		var s Stack
		s.Push(1)

		v, err := s.Pop()
		if v != 1 {
			t.Errorf("expected 1, got %d\n", s.Top())
		} else if err != nil {
			t.Error("err is not nil")
		}
	})

	t.Run("push multiple then pop all", func(t *testing.T) {
		var s Stack
		s.Push(1)
		s.Push(2)
		s.Push(3)
		v1, _ := s.Pop()
		v2, _ := s.Pop()
		v3, _ := s.Pop()

		if v1 != 3 {
			t.Errorf("expected 3, got %d\n", v1)
		} else if v2 != 2 {
			t.Errorf("expected 2, got %d\n", v2)
		} else if v3 != 1 {
			t.Errorf("expected 1, got %d\n", v3)
		}
	})

	t.Run("stack empty", func(t *testing.T) {
		var s Stack
		if !s.Empty() {
			t.Error("expected stack to be empty")
		}
	})

	t.Run("stack full", func(t *testing.T) {
		var s Stack
		for i := 0; i < 50; i++ {
			s.Push(i)
		}
		if !s.Full() {
			t.Error("expected stack to be full")
		}
	})

	t.Run("pop with empty stack", func(t *testing.T) {
		var s Stack
		_, err := s.Pop()
		if err == nil {
			t.Error("expected err, got nil")
		}
	})

	t.Run("push with full stack", func(t *testing.T) {
		var s Stack
		for i := 0; i < 50; i++ {
			s.Push(i)
		}
		_, err := s.Push(50)
		if err == nil {
			t.Error("expected err, got nil")
		}
	})
}
