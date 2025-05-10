int lengthOfLastWord(char* s) {
    // malloc要加一，因為要留空間給\0
    char *str = (char*)malloc((strlen(s)+1)*sizeof(char));
    strcpy(str, s);
    // strtok ->找到第一個不是' '的字串
    // 如果沒有了會回傳NULL
    char *token = strtok(str, " ");
    char *tmp_token;
    while(token!=NULL){
        // 指標位置之間只要這樣處理就好了，把位置賦予另一個指標
        tmp_token = token;
        // NULL表示會繼續使用原本的string
        token = strtok(NULL, " ");
    }
    return strlen(tmp_token);
}
