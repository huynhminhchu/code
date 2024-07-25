int multcnt = 0;

void multvec(int *x, int *y, int *z, int n){
    int i;
    
    multcnt++;

    for (i = 0; i < 5; i++){
        z[i] = x[i] * y[i];
    }
}