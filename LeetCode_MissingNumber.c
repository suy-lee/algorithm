/* heapify the subtree with root i */
void heapify(int *arr, int n, int i)
{
    // store largest as the root element
    int largest = i;
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    // now check whether the right and left right is larger than the root or not
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
 
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
 
    // if the root is smaller than the children then swap it with the largest children's value
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        // again heapify that side of the heap where the root has gone
        heapify(arr, n, largest);
    }
}

/* sorts the given array of n size */
void heapSort(int *arr, int n)
{
    // build the binary max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
 
    // sort the max heap
    for (int i = n - 1; i >= 0; i--)
    {
        // swap the root node and the last leaf node
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
 
        // again heapify the max heap from the root 
        heapify(arr, i, 0);
    }
}

int missingNumber(int* nums, int numsSize){
    int res = -1;
    bool flag = false;
    int i = 1;
    heapSort(nums, numsSize);

    // i) if numsSize == 1
    if (numsSize == 1) {
        if (nums[0] == 0) res = 1;
        else res = 0;
        return res;
    }

    // ii) numsSize > 1 and first element (0) is missing
    if (nums[0] != 0) {
        res = 0;
        return res;
    }

    for (; i < numsSize; i++) {
        if (nums[i] != (nums[i-1]+1)) {
            res = nums[i-1]+1;
            flag = true;
        }
    }

    // iii) last element is missing
    if (!flag) res = nums[i-1]+1;
    return res;
}
