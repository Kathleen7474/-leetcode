bool isSubsequence(char* s, char* t) {
    int j = 0;
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (strlen(s)==0)
        return true;
    for (int i = 0;i<s_len;i++){
        for (;j<t_len;j++){
            if(s[i]==t[j]){
                if (i==s_len-1){
                    // printf("%d",j);
                    return true;
                }
                j++;
                break;
            }
        }
    }
    return false;
}
