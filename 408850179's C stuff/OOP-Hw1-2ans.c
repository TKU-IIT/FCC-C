void sum_of_each_line(FILE *f){
    char line[201];
    while(fgets(line, 201, f)!=0){
        double v, sum = 0;
        int n;
        char *p = line;
        while(sscanf(p, "%lf%n", &v, &n)>0){
            sum += v;
            p += n;
        }
        printf("%lf\n", sum);
    }
}