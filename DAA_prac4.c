#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF INT_MAX
int A[MAX];
int n;
struct SubArray{
    int low;
    int high;
    int sum;
};
//Function to find the maximum crossing subarray
struct SubArray Max_Crossing_SubArray(int A[], int low, int mid, int high){
    int left_sum = -INF;
    int sum = 0;
    int max_left = mid;
    for(int i = mid; i >= low; i--){
        sum += A[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -INF;
    sum = 0;
    int max_right = mid + 1;
    for(int j = mid + 1; j <= high; j++){
        sum += A[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    struct SubArray result;
    result.low = max_left;
    result.high = max_right;
    result.sum = left_sum + right_sum;
    return result;
}
//Function to find the maximum subarray 
struct SubArray Max_Sum_SubArray(int A[], int low, int high){
    if(low == high){
        struct SubArray Base;
        Base.low = low;
        Base.high = high;
        Base.sum = A[low];
        return Base;
    }
    else{
        int mid = (low + high) / 2;
        struct SubArray Left = Max_Sum_SubArray(A, low, mid);
        struct SubArray Right = Max_Sum_SubArray(A, mid + 1, high);
        struct SubArray Cross = Max_Crossing_SubArray(A, low, mid, high);
        if(Left.sum >= Right.sum && Left.sum >= Cross.sum)
            return Left;
        else if(Right.sum >= Left.sum && Right.sum >= Cross.sum)
            return Right;
        else
            return Cross;
    }
}
struct SubArray Max_Sum_SubArray_With_Constraint(int A[], int n, int K){
    int arr[n + 1];
    arr[0] = 0;
    for(int i = 0; i < n; i++)
        arr[i + 1] = arr[i] + A[i];

    struct SubArray best = {-1, -1, INT_MIN};
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = arr[j + 1] - arr[i];
            if(sum <= K && sum > best.sum){
                best.low = i;
                best.high = j;   
                best.sum = sum;
            }
        }
    }
    return best;
}

int main(){
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int K;
    printf("Enter the constraint: ");
    scanf("%d", &K);
    if(n == 0){
        printf("Empty array, no subarray exists.\n");
        return 0;
    }
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    struct SubArray s = Max_Sum_SubArray_With_Constraint(A, n, K);
    if(s.low != -1)
        printf("Maximum contiguous subarray is from index %d to %d with sum %d\n", s.low, s.high, s.sum);
    else
        printf("No subarray found with constrained sum %d\n", K);
    return 0;
}