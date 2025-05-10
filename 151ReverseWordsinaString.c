char* output_s;
char* ptr;
void nextToken(char* s){
    char *token = strtok(s, " ");
    if(token==NULL)
        return;
    // 因為strtok的作用範圍不是只有這個Function
    // ps. multithread或是多個function互相呼叫strtok會有race condition
    nextToken(NULL);
    strcpy(ptr, token);
    ptr[strlen(token)] = ' ';
    ptr = ptr+strlen(token)+1;
    return;
}

char* reverseWords(char* s) {
    output_s = (char*)malloc((strlen(s)+1)*sizeof(char));
    ptr = output_s;
    char* tmp_str = (char*)malloc((strlen(s)+1)*sizeof(char));
    strcpy(tmp_str, s);
    nextToken(tmp_str);
    ptr = ptr-1;
    ptr[0] = '\0';
    printf("output s %s", output_s);
    return output_s;
}
