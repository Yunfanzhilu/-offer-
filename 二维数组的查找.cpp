class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
     bool find=false;
        int i=7;
        int rows=array.size();
        int columns=array[0].size();
       
        if((rows>0)&&(columns>0))
        {
            int row=0;
            int column=columns-1;
            while((row<rows)&&(column>=0))
            {
                if(array[row][column]==target)
                {
                    find=true;
                break;
                }
                else if(array[row][column]>target)
                {
                    column--;
                }
                else
                {
                    row++;
                }
                
            }
        }
        return find;
    }
};


二维数组在不知道行数、列数的时候，怎么求？（二维数组中的查找）
答：array.size(); 行数
array[0].size();   列数
