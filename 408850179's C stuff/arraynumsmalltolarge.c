#include<stdio.h>

void print_array(int a[], int n_elen){
	int c;
	c = 0;
	while(c < n_elen){
		//每次循環就印一個指數(c)
		printf("%d ", a[c]);
		c = c + 1;
	}
	printf("\n");
}

int read_values(int orig[], int max_n_input){
	int n_input, v;
	
	n_input = 0;
	//(n_input) 表示輸入了多少個有效的數字
	scanf("%d", &v);
	while(n_input < max_n_input){
		if (v <= 0){
			//當輸入0或負數時停止這個步驟
			break;//備註:負數不會顯現但也在陣列裡面
			//陣列是從[0號]開始數，負數剛好補齊陣列少一數的特點
		}
		orig[n_input] = v;
		n_input = n_input + 1;
		if(n_input < max_n_input){
			//如果還沒輸入20個數字可以繼續輸入
			scanf("%d", &v);
		}
	}
	return n_input;
}

int min_idx(int orig[], int n_input){
	int c, min, min_i, orig_i;
	
	//這部分 where it choose a random non negative number to compare the other numbers with
	c = 0;
	while(orig[c] <= 0){
		c = c + 1;
	}
	//c is index number of that randomly chosen number

	min = orig[c];
	min_i = c;
	
	orig_i = c + 1;
	while(orig_i < n_input){
		//if this if didn't trigger at all means the first index has the smallest number
		if(orig[orig_i] > 0 && orig[orig_i] < min){
			//check whick non negative number is the smallest
			//omits repeated problem because each duplicated number will be flagged individually
			min = orig[orig_i];
			min_i = orig_i;
			//tracks both the smallest number and the placement of that number in the array's index
		}
		orig_i = orig_i + 1;
		//ticks up and check the next one
	}

	//reports the index of the smallest number
	return min_i;
}

int main(int argc, char**argv){
	
	int n_input, res[20], res_i, orig[20], orig_i, c, v, min, min_i;
	
	n_input = read_values(orig, 20);
	
	printf("entered numbers = %d\n", n_input);
	print_array(orig, n_input);
	
	res_i = 0;
	while(res_i < n_input) {
		
		//recieves the index of the smallest number in orig[]
		min_i = min_idx(orig, n_input);
		//logs the smallest number into the nth index in res[] (n being the itration number of this loop)
		res[res_i] = orig[min_i];
		//flag that number by turing it negative in orig[] so that it won't be checked again in min_idx()
		orig[min_i] = -orig[min_i];
		
		res_i = res_i + 1;
	
	}
	
	print_array(res, n_input);
	return 0;
}