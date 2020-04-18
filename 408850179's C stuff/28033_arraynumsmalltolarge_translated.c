#include<stdio.h>

//printing function
//輸出程序
void print_array(int a[], int n_elen){
	int c;
	c = 0;
	while(c < n_elen){
		//print each arrary index by each loop
		//以迴圈輸出陣列裡的值
		printf("%d ", a[c]);
		c = c + 1;
	}
	printf("\n");
}

//reading function
//輸入程序
int read_values(int orig[], int max_n_input){
	int n_input, v;
	
	n_input = 0;
	//n_input tracks the quantity of inputs
	//n_input變數記錄輸入項目的數量
	scanf("%d", &v);
	while(n_input < max_n_input){
		if (v <= 0){
			//stop recieving inputs if a negative number is entered
			//如果輸入了負數就終止輸入程序
			break;
		}
		orig[n_input] = v;
		n_input = n_input + 1;
		if(n_input < max_n_input){
			//if this is not breaking the array's 20 limit then allow further input
			//如果輸入項目的數量沒有超過20就繼續輸入程序
			scanf("%d", &v);
		}
	}
	return n_input;
	//report the quantity of inputs
	//回傳輸入項目的數量給主程序
}

//comparing function
//比較程序
int min_idx(int orig[], int n_input){
	int c, min, min_i, orig_i;
	
	//the part where it choose a random non negative number to compare the other numbers with
	//從陣列中隨機挑選一個自然數進行比較
	c = 0;
	while(orig[c] <= 0){
		c = c + 1;
	}
	//c is index number of that randomly chosen number
	//c是那個隨機數的編號

	min = orig[c];
	min_i = c;
	
	orig_i = c + 1;
	while(orig_i < n_input){
		//if this if didn't trigger at all means the first index has the smallest number
		//如果電腦沒跑這個程序代表第一個挑到的就是陣列的最小值
		if(orig[orig_i] > 0 && orig[orig_i] < min){
			//check which non negative number is the smallest
			//這個程序是用來找陣列最小值的
			//omits repeated problem because each duplicated number will be flagged individually
			//將重複的數字個別標記
			min = orig[orig_i];
			min_i = orig_i;
			//tracks both the smallest number and the placement of that number in the array's index
			//記憶目前為止檢查過最小的值和它在陣列中的編號
		}
		orig_i = orig_i + 1;
		//ticks up and check the next one
		//檢查陣列裡下一個值
	}

	//reports the index of the smallest number
	//回傳陣列最小值的編號給主程序
	return min_i;
}

//main function
//主程序
int main(int argc, char**argv){
	
	int n_input, res[20], res_i, orig[20], orig_i, c, v, min, min_i;
	
	n_input = read_values(orig, 20);
	//execute reading function
	//跑輸入程序
	
	printf("entered numbers = %d\n", n_input);
	print_array(orig, n_input);
	//execute printing function, print original inputs
	//跑輸出程序，輸出原有的輸入值
	
	res_i = 0;
	while(res_i < n_input) {
		
		//recieves the index of the smallest number in orig[]
		//接收陣列最小值的編號
		min_i = min_idx(orig, n_input);
		//execute comparing function
		//跑比較程序
		//logs the smallest number into the nth index in res[] (n being the iteration number of this loop)
		//把陣列編號n的內容指定為陣列最小值 (n是這個迴圈重複的次數)
		res[res_i] = orig[min_i];
		//flag that number by turing it negative in orig[] so that it won't be checked again in min_idx()
		//把指定完的陣列最小值變為負數，這樣再跑一次迴圈的時候這個數字就會被跳過，陣列最小值變成下一個值
		orig[min_i] = -orig[min_i];
		
		res_i = res_i + 1;
	
	}
	
	print_array(res, n_input);
	//execute printing function, print results
	//跑輸出程序，輸出重新排序過的結果
	return 0;
}