// A binary search based function to find the position where item should be inserted in a[low..high] 
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low;   
    int mid = (low + high)/2;   
    if(item == a[mid]) 
        return mid+1;   
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 


// A binary search function. It returns location of x in given array a[low..high] is present, otherwise -1 
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high >= low) { 
        int mid = low + (high - low) / 2; 
        if (a[mid] == item) 
            return mid;  
        if(item > a[mid]) 
          return binarySearch(a, item, mid+1, high); 
        return binarySearch(a, item, low, mid-1); 
    } 
    return -1; 
} 
