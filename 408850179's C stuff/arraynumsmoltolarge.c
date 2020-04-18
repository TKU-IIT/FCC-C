#include<stdio.h>

void print_array(int a[], int n_elen){
	int c;
	c = 0;
	while(c<n_elen){
		printf("%d ", a[c]);
		c = c + 1;
	}
	printf("\n");
}

int read_values(int orig[], int max_n_input){
	int n_input, v;
	
	n_input = 0;
	scanf("%d", &v);
	while(n_input<max_n_input){
		if (v <= 0){
			break;
		}
		orig[n_input] = v;
		n_input = n_input + 1;
		if(n_input<max_n_input){
			scanf("%d", &v);
		}
	}
	return n_input;
}

int min_idx(int orig[], int n_input){
	int c, min, min_i, orig_i;
	
	c = 0;
	while(orig[c]<=0){
		c = c + 1;
	}
	min = orig[c]; min_i = c;
	
	orig_i = c + 1;
	while(orig_i<n_input){
		if(orig[orig_i]>0 && orig[orig_i]<min){
			min = orig[orig_i]; min_i = orig_i;
		}
		orig_i = orig_i + 1;
	}
	return min_i;
}

int main(int argc, char**argv){
	
	int n_input, res[20], res_i, orig[20], orig_i, c, v, min, min_i;
	
	n_input = read_values(orig, 20);
	
	printf("n = %d\n", n_input);
	print_array(orig, n_input);
	
	res_i = 0;
	while(res_i < n_input) {
		
		min_i = min_idx(orig, n_input);
		res[res_i] = orig[min_i];
		orig[min_i] = -orig[min_i];
		
		res_i = res_i + 1;
	
	}
	
	print_array(res, n_input);
	return 0;
}