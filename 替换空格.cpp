class Solution {
public:
    //length为字符数组的总容量
	void replaceSpace(char *str,int length) {
           if(str==NULL)
           {
               return;
           }
        //判断原字符串长度和空格数目
        int OrignalLength=0;
        int NumOfBlank=0;
        int i=0;
        while(str[i]!='\0')
        {
            ++OrignalLength;
            if(str[i]==' ')
            {
                ++NumOfBlank;
                
            }
            ++i;
        }
	
    
    //新的字符串的长度 
        int NewLength=OrignalLength+NumOfBlank*2;
        int p1=OrignalLength,p2=NewLength;
        //替换字符串空格
        int j,y=2,k=87,l=92;
        for(j=0;j<NumOfBlank;j++)
        {
        while(str[p1]!=' ')
        {
            str[p2]=str[p1];
            p1--;
            p2--;
        }
         
            str[p2]='0';
            str[--p2]='2';
            str[--p2]='%';
            p1--;
            p2--;
            
        }
    }
};



(1)char str1[]=”hello world”   (2)char str2[]=”hello world”
(3)char*str3=”hello world”    (4)char*str4=”hello world” （替换空格）
答：
1、C/C++把常量字符串放到单独的一个内存区域。当几个指针赋值给相同的常量字符串时，它们实际上会指向相同的内存地址。题目中问str1==str2?、str3==str4?(1)和(2)不相等因为两个初始地址不同，(3)和(4)相等因为它们在内存中只有一个拷贝，str3和str4指向同一个地址。
2、这道题本身算法思想不难，注意之后做字符串的题要考虑“从后往前”的算法，可能比“从前往后”的算法更好。
3、编程过程中两个地方要稍微注意：
（1）模板中length是指字符数组的总容量（可以巨长），而在编程中定义的OriginalLength才是原始字符串的真实长度。
（2）编程时要注意p1—和—p1的区别，虽然直观看上去很简单，但在编程的时候容易出现错误导致内存溢出等等。
