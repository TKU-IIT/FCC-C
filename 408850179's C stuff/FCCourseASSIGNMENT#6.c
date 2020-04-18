char *dup_str(const char *s) {
    int l;
    l = strlen(s);
    if (l<100) {
        char *ret = (char*)malloc(l+1);
        strcpy(ret, s);
        return ret;
    } else {
        return (char*)0;
    }
}