void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
 
bool containsDuplicate(int *nums, int numsSize){
    heapSort(nums, numsSize);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) return true;
    }
    return false;
}
