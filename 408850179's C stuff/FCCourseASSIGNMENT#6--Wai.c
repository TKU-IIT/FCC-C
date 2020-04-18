char *dup_str(const char *s){
	char *cop;
	char arrlen = 100;
	cop = (char*) malloc( arrlen * sizeof(char));
	if(strlen(s)<=100){
		strcpy(cop, s);
		return cop;
	}else{
		return 0;
	}
}