int compress(char* chars, int charsSize) {
    // printf("charSize %d, ", charsSize);
    // 這裡不適合用strtok因為字串結尾不確定
    int start = 0;
    char*ptr = chars;

    // printf("string %s\n", chars);
    for(int i = 1;i<charsSize;i++){
        if(chars[start]!=chars[i]){
            char*fill = (char*)malloc(6*sizeof(char));
            fill[0] = chars[start];
            if((i-start)>1)
                sprintf(fill+1, "%d", i-start);
            else
                fill[1] = '\0';
            // printf("fill %s, len %d, ", fill, (int)strlen(fill));
            // char* tmp = (char*)malloc((i-start+1)*sizeof(char));
            // strncpy(tmp, chars+start,i-start);
            // tmp[i-start] = '\0';
            // printf("group: %s, i = %d, count = %d\n", tmp, i, i-start);
            strncpy(ptr, fill, (int)strlen(fill));
            ptr = ptr+(int)(strlen(fill));
            // printf("new string: %s\n", chars);
            // free(tmp);
            free(fill);
            start = i;
        }
    }
    // 結尾
    if(charsSize>start){
        char*fill = (char*)malloc(6*sizeof(char));
        fill[0] = chars[start];
        if((charsSize-start)>1)
            sprintf(fill+1, "%d", charsSize-start);
        else
            fill[1] = '\0';
        // printf("fill %s, len %d, ", fill, (int)strlen(fill));

        // char* tmp = (char*)malloc((charsSize-start+1)*sizeof(char));
        // strncpy(tmp, chars+start,charsSize-start);
        // tmp[charsSize-start] = '\0';
        // printf("group last: %s, count = %d\n", tmp, charsSize-start);
        strncpy(ptr, fill, (int)strlen(fill));
        // printf("new string: %s\n", chars);
        ptr = ptr+(int)(strlen(fill));
        if(ptr-chars<charsSize)
            ptr[0] = '\0';
        // printf("end pos %d\n", ptr-chars);
        // free(tmp);
        free(fill);
    }
    
    
    return ptr-chars;
}
