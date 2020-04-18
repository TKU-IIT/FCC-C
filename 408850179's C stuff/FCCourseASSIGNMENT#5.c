void find_min_max(int n1, int n2, int n3, int n4, int *min_ptr, int *max_ptr) {
    int min1, min2, max1, max2;
    if (n1 < n2) {
        min1 = n1; max1 = n2;
    } else {
        min1 = n2; max1 = n1;
    }
    if (n3 < n4) {
        min2 = n3; max2 = n4;
    } else {
        min2 = n4; max2 = n3;
    }
    if (min1 < min2) {
        *min_ptr = min1;
    } else {
        *min_ptr = min2;
    }
    if (max1 > max2) {
        *max_ptr = max1;
    } else {
        *max_ptr = max2;
    }