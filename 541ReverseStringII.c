#define min(a, b) ((a) < (b) ? (a) : (b))
char* reverseStr(char* s, int k) {
    int string_size = strlen(s);
    int times = string_size/(2*k);
    // printf("string size %d, times %d\n",string_size, times);
    char* output = (char*)malloc((string_size+1) * sizeof(char));
    strcpy(output, s);
    int i = 0, j = 0;
    for(j = 0;j<times;j++){
        for(i = 0; i<k;i++){
            output[2*k*j+i] = s[2*k*(j+1)-k-i-1];
        }
        strcpy(output+2*k*j+k, s+2*k*j+k);
    }
    printf("final idx = %d \n",2*k*j+k);
    // 最後剩下有大於一節的k
    if(2*k*j+k<string_size){
        for(i = 0; i<k;i++){
            output[2*k*j+i] = s[2*k*(j+1)-k-i-1];
        }
        strcpy(output+2*k*j+k, s+2*k*j+k);
    }else if(2*k*j+k>=string_size){
        int end_idx = string_size - 2*k*j;
        for(i = 0;i<end_idx;i++){
            output[2*k*j+i] = s[string_size-i-1];
        }
        strcpy(output+2*k*j+i, s+2*k*j+i);
    }
    if(string_size<=k){
        k = min(string_size, k);
        for(i = 0; i<k;i++){
            // printf("output idx %d, s idx %d, ",i,k-i-1);
            // printf("s element %c\n", s[k-i-1]);
            output[i] = s[k-i-1];
        }
        strcpy(output+k, s+k);
    }
    // output[i] = '\0';
    printf("output: %s\n", output); 
    printf("s: %s\n", s); 
    // ps output+k這個寫法就是因為這樣會是呼叫下k個char的位置
    // strcpy(output+k, s+k);
    printf("Result: %s\n", output); 
    return output;
}
