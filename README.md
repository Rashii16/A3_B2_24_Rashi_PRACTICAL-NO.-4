# A3_B2_24_Rashi_PRACTICAL-NO.-4
Aim: Implement maximum sum of subarray for the given scenario of resource allocation using the divide and conquer approach.

Problem Statement:
A project requires allocating resources to various tasks over a period of time. Each task requires
a certain amount of resources, and you want to maximize the overall efficiency of resource
usage. You're given an array of resources where resources[i] represents the amount of resources
required for the i

th task. Your goal is to find the contiguous subarray of tasks that maximizes

the total resources utilized without exceeding a given resource constraint.
Handle cases where the total resources exceed the constraint by adjusting the subarray window
accordingly. Your implementation should handle various cases, including scenarios where
there's no feasible subarray given the constraint and scenarios where multiple subarrays yield
the same maximum resource utilization.
1. Basic small array
• resources = [2, 1, 3, 4], constraint = 5
o Best subarray: [2, 1] or [1, 3] → sum = 4
o Checks simple working.

2. Exact match to constraint
• resources = [2, 2, 2, 2], constraint = 4
o Best subarray: [2, 2] → sum = 4
o Tests exact utilization.

3. Single element equals constraint
• resources = [1, 5, 2, 3], constraint = 5
o Best subarray: [5] → sum = 5
o Tests one-element solution.

4. All elements smaller but no combination fits
• resources = [6, 7, 8], constraint = 5
o No feasible subarray.
o Tests "no solution" case.

5. Multiple optimal subarrays
• resources = [1, 2, 3, 2, 1], constraint = 5
o Best subarrays: [2, 3] and [3, 2] → sum = 5
o Tests tie-breaking (should return either valid subarray).

6. Large window valid
• resources = [1, 1, 1, 1, 1], constraint = 4
o Best subarray: [1, 1, 1, 1] → sum = 4
o Ensures long window works.

7. Sliding window shrink needed
• resources = [4, 2, 3, 1], constraint = 5
o Start [4,2] = 6 (too big) → shrink to [2,3] = 5.
o Tests dynamic window adjustment.

8. Empty array
• resources = [], constraint = 10
o Output: no subarray.
o Edge case: empty input.

9. Constraint = 0
• resources = [1, 2, 3], constraint = 0
o No subarray possible.
o Edge case: zero constraint.

10. Very large input (stress test)
• resources = [1, 2, 3, ..., 100000], constraint = 10^9
o Valid subarray near full array.
o Performance test.
