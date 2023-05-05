class Solution {
public:

    void change(vector<vector<int>>& mat,vector<vector<int>>& return_mat,int x,int y,int value){
        int m = mat.size();
        int n = mat[0].size();
        return_mat[x][y] = value;
        // if(y>4900)
        //     cout<<x<<" "<<y<<" "<<value<<endl;

        // 如果上大於自己+1
        if(x>0&&return_mat[x-1][y]>value+1)
            change(mat,return_mat,x-1,y,value+1);
        // 左
        if(y>0&&return_mat[x][y-1]>value+1)
            change(mat,return_mat,x,y-1,value+1);
        // 下
        if(x<m-1&&return_mat[x+1][y]>value+1)
            change(mat,return_mat,x+1,y,value+1);
        // 右
        if(y<n-1&&return_mat[x][y+1]>value+1)
            change(mat,return_mat,x,y+1,value+1);
        // if(y<100)
        //     cout<<"end function "<<x<<" "<<y<<endl;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> return_mat(m, vector<int>(n, 0));
        cout<<m<<" mn "<<n<<endl;;
        for (int i = 0;i<m;i++){
            cout<<""<<i;
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    change(mat,return_mat,i,j,0);
                }
                else{
                    // cout<<"value1. "<<i<<j;
                    int min = 99999;
                    if (i-1>=0){
                        min = return_mat[i-1][j];
                    }
                    if(j-1>=0&&return_mat[i][j-1]<min)
                        min = return_mat[i][j-1];
                    // cout<<". inside"<<endl;
                    if(i==0&&j==0)
                        min = 99999;
                    return_mat[i][j] = min+1;
                    
                }
                
            }

        }
        return return_mat;
    }
};

