#include "pch.h"
#include <iostream>
#include "..\mp2-lab4-queue\TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size) {
	ASSERT_NO_THROW(TQueue<int> qu(5));
}

TEST(TQueue, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> qu(-5));
}

TEST(TQueue, cant_create_queue_with_zero_size) {
	ASSERT_ANY_THROW(TQueue<int> qu(0));
}

TEST(TQueue, cant_create_one_element_queue) {
	ASSERT_ANY_THROW(TQueue<int> qu(1));
}

TEST(TQueue, new_created_queue_is_empty) {
	TQueue<int> qu(5);
	ASSERT_TRUE(qu.empty());
}

TEST(TQueue, new_created_queue_is_not_full) {
	TQueue<int> qu(5);
	ASSERT_FALSE(qu.full());
}

TEST(TQueue, full_queue_is_not_empty) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	ASSERT_FALSE(qu.empty());
}

TEST(TQueue, full_queue_is_full) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	ASSERT_TRUE(qu.full());
}

TEST(TQueue, not_empty_queue_is_not_empty) {
	TQueue<int> qu(5);
	qu.push(0);

	ASSERT_FALSE(qu.empty());
}

TEST(TQueue, not_empty_queue_is_not_full) {
	TQueue<int> qu(5);
	qu.push(0);

	ASSERT_FALSE(qu.full());
}

TEST(TQueue, can_create_copied_queue) {
	TQueue<int> qu(5);
	ASSERT_NO_THROW(TQueue<int> copy = qu);
}

TEST(TQueue, copied_queue_is_equal_to_source_one) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	TQueue<int> copy = qu;

	EXPECT_EQ(copy, qu);
}

TEST(TQueue, copied_queue_has_its_own_memory) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	TQueue<int> copy = qu;
	copy.clear();
	for (int i = 0; i < 5; i++) {
		copy.push(i + 1);
	}

	for (int i = 0; i < 5; i++) {
		EXPECT_NE(qu.pop(), copy.pop());
	}
}

TEST(TQueue, can_assign_queues_of_equal_sizes) {
	TQueue<int> qu1(5);
	for (int i = 0; i < 5; i++) {
		qu1.push(i);
	}

	TQueue<int> qu2(5);
	qu2 = qu1;

	EXPECT_EQ(qu2, qu1);
}

TEST(TQueue, can_assign_queues_of_different_sizes) {
	TQueue<int> qu1(5);
	for (int i = 0; i < 5; i++) {
		qu1.push(i);
	}

	TQueue<int> qu2(10);
	qu2 = qu1;

	EXPECT_EQ(qu2, qu1);
}

TEST(TQueue, can_assign_queue_to_itself) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	qu = qu;

	EXPECT_EQ(qu, qu);
}

TEST(TQueue, equal_queues_comparison_returns_true) {
	TQueue<int> qu1(5);
	for (int i = 0; i < 5; i++) {
		qu1.push(i);
	}

	TQueue<int> qu2(5);
	for (int i = 0; i < 5; i++) {
		qu2.push(i);
	}

	EXPECT_EQ(qu1, qu2);
}

TEST(TQueue, unequal_queues_comparison_returns_false) {
	TQueue<int> qu1(5);
	for (int i = 0; i < 5; i++) {
		qu1.push(i);
	}

	TQueue<int> qu2(5);
	for (int i = 0; i < 5; i++) {
		qu2.push(i + 1);
	}

	EXPECT_NE(qu1, qu2);
}

TEST(TQueue, queues_with_different_maxsizes_are_not_equal) {
	TQueue<int> qu1(5);
	TQueue<int> qu2(10);

	EXPECT_NE(qu1, qu2);
}

TEST(TQueue, can_push_and_pop_single) {
	TQueue<double> qu(5);
	double num = 25.12;
	double popped;

	ASSERT_NO_THROW(qu.push(num));
	ASSERT_NO_THROW(popped = qu.pop());
	EXPECT_EQ(popped, num);
}

TEST(TQueue, can_push_and_pop_three) {
	TQueue<double> qu(5);
	double num1 = 2.34;
	double num2 = 5.67;
	double num3 = 8.91;

	ASSERT_NO_THROW(qu.push(num1));
	ASSERT_NO_THROW(qu.push(num2));
	ASSERT_NO_THROW(qu.push(num3));

	ASSERT_NO_THROW(qu.pop() == num1);
	ASSERT_NO_THROW(qu.pop() == num2);
	ASSERT_NO_THROW(qu.pop() == num3);
}

TEST(TQueue, cant_push_to_a_full_queue) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	ASSERT_ANY_THROW(qu.push(5));
}

TEST(TQueue, cant_pop_from_an_empty_queue) {
	TQueue<int> qu(5);
	ASSERT_ANY_THROW(qu.pop());
}

TEST(TQueue, can_clear_queue) {
	TQueue<int> qu(5);
	for (int i = 0; i < 5; i++) {
		qu.push(i);
	}

	ASSERT_NO_THROW(qu.clear());
}

TEST(TQueue, cleared_queue_is_empty) {
	TQueue<int> qu(10);
	for (int i = 0; i < 10; i++) {
		qu.push(i);
	}

	qu.clear();
	ASSERT_TRUE(qu.empty());
}

TEST(TQueue, cleared_queue_is_not_full) {
	TQueue<int> qu(10);
	for (int i = 0; i < 10; i++) {
		qu.push(i);
	}

	qu.clear();
	ASSERT_FALSE(qu.full());
}