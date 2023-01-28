from collections import deque

stack = deque(map(int, input().split()))
stack_a = deque()
stack_b = deque()

# 크기 순으로 index 재설정
for n1 in stack:
	cnt = 0
	for n2 in stack:
		if n1 > n2:
			cnt += 1
	stack_a.append(cnt)

def a_to_b():
	size = len(stack_a)
	scale = 0.000000053 * size * size + 0.03 * size + 14.5
	i = 0
	while len(stack_a):
		top = stack_a[0]
		if top <= i:
			stack_b.appendleft(stack_a.popleft())
			print("pb")
			i += 1
		elif top > i and top <= i + scale:
			stack_b.appendleft(stack_a.popleft())
			print("pb")
			stack_b.rotate(-1)
			print("rb")
			i += 1
		elif top > i + scale:
			stack_a.rotate(-1)
			print("ra")

def b_to_a():
	while len(stack_b):
		big_idx = stack_b.index(max(stack_b))
		mid = len(stack_b) // 2
		if big_idx > mid:
			while big_idx < len(stack_b):
				stack_b.rotate()
				print("rrb")
				big_idx += 1
		elif big_idx <= mid:
			while big_idx > 0:
				stack_b.rotate(-1)
				print("rb")
				big_idx -= 1
		stack_a.appendleft(stack_b.popleft())
		print("pa")

a_to_b()
# print(stack_a)
# print(stack_b)
b_to_a()
# print(stack_a)
# print(stack_b)