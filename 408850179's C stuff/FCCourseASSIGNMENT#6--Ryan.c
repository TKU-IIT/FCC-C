char *dup_str(const char *s){
    if(strlen(s) < 100){
        char *r = (char*) malloc(strlen(s+1));
        memcpy(r, s, strlen(s)+1);
        return r;
    }else{
        return 0;
    }
}