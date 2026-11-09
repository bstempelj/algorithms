package main

import "testing"

func TestQueue(t *testing.T) {
	t.Run("empty", func(t *testing.T) {
		var q Queue
		if !q.Empty() {
			t.Error("expected empty queue")
		}
	})

	t.Run("single enqueue then dequeue", func(t *testing.T) {
		var q Queue
		q.Enqueue(1)
		x := q.Dequeue()
		if x != 1 {
			t.Errorf("expected 1, got %d", x)
		}
	})

	t.Run("three enqueue then three dequeue", func(t *testing.T) {
		var q Queue
		q.Enqueue(1)
		q.Enqueue(2)
		q.Enqueue(3)
		x, y, z := q.Dequeue(), q.Dequeue(), q.Dequeue()
		if x != 1 {
			t.Errorf("expected 1, got %d", x)
		}
		if y != 2 {
			t.Errorf("expected 2, got %d", x)
		}
		if z != 3 {
			t.Errorf("expected 3, got %d", x)
		}
	})

	t.Run("overflow", func(t *testing.T) {
		var q Queue
		for i := 0; i < QueueSize; i++ {
			q.Enqueue(i)
		}
		q.Enqueue(-1)

		for i := 0; i < QueueSize; i++ {
			q.Dequeue()
		}
		x := q.Dequeue()
		if x != -1 {
			t.Errorf("expected -1, got %d", x)
		}
	})
}
