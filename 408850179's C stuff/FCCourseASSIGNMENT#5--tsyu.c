void find_min_max(int n1, int n2, int n3, int n4, int *min_ptr, int *max_ptr){
	int min = n1;
	int max = n2;
	int a[4] = {n1, n2, n3, n4};
	for(int i = 0; i<4; i++){
		if(a[i]<min) min = a[i];
		else if(a[i]>max) max =a[i];
	}
	*max_ptr = max;
	*min_ptr = min;
}