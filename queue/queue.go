package main

const QueueSize = 10

type Queue struct {
	data [QueueSize]int
	head uint
	tail uint
}

func (q *Queue) Enqueue(x int) {
	if q.tail == QueueSize {
		q.tail = 0
	}
	q.data[q.tail] = x
	q.tail++
}

func (q *Queue) Dequeue() int {
	if q.head == QueueSize {
		q.head = 0
	}
	x := q.data[q.head]
	q.head++
	return x
}

func (q *Queue) Empty() bool {
	return q.head == q.tail
}
