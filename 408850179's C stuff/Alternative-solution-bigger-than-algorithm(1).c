#include <stdio.h>

int main(int argc, char **argv) {
	int n[20], i, h, r, c, j, e, o[20];
	
	for(i = 0; i < 20; i++){
		//before the array reaches 20 in size allow more inputs
		//如果輸入項目的數量沒有超過20就繼續輸入程序
		scanf("%d", &h);
		if(h < 1){
			//stop recirving inputs when input is 0 or negative
			//如果輸入了負數就終止輸入程序
			r = i;
			i = 20;
		} else {
			r = i + 1;
			n[i] = h;
		}
	}

	//r is the number of records in the array
	//r變數記錄輸入項目的數量
	for(i = 0; i < r; i++){
		c = 0;
		e = 0;
		//this works by counting how many numbers are smaller than the tested number
		//and putting them in another array for printing
		for(j = 0; j < r; j++){
			//one number is checked each time this loop runs
			if(n[i] > n[j]){
				c = c + 1;
				//c counts how many unique numbers are smaller than the number tested
			}
			if(n[i] == n[j] && i > j){
				//this loop will be used when there is already a number in the result array (n[])
				e = e + 1;
			}
		}
		printf("c:%d e:%d\n", c, e);
		//c means the ranking of that number tested (start from 0)
		//e means the duplicate number of the tested number
		c = c + e;
		o[c] = n[i];
	}
	for(i = 0;i < r;i++){
		//printing the array
		printf("%d ", o[i]);
	}
	printf("\n");

	return 0;
}