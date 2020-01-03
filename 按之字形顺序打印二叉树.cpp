题目描述：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
    之前在普通二叉树的建立和遍历过程中，写过用队列的思想打印二叉树的经典代码，这道题我的算法思想就是从这段经典代码想过来。
    经典队列打印二叉树代码：
    //按层打印二叉树（队列的思想）
/*vector<int> PrintFromTopToBottom(BiTreeNode* T) {
	queue<BiTreeNode*> q;
	q.push(T);
	vector<int> r;
	while (!q.empty()) {
		T = q.front(); q.pop();
		if (!T) continue;
		r.push_back(T->data);
		q.push(T->lchild);
		q.push(T->rchild);
	}
	return r;

}*/
     这里很巧妙地利用队列先进先出的性质打印二叉树，仔细看一会儿就能看明白。
     这道题利用建立两个栈，一个正向打印，一个反向打印，number为记录到了哪一层。
//二叉树结点结构
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>>result;
       //TreeNode* TempNodeLeft,TempNodeRight;
        int number=2,num1=0,num2=0;
        stack<TreeNode *>s1;
        stack<TreeNode *>s2;
     int temp=9;
        vector<int>data1,data2;
         if(pRoot)//要加这句话
         {
        s1.push(pRoot);
         }
 
        while((!s1.empty())||(!s2.empty()))
        {
           /*if(number==1)
            {
                pRoot=s1.top();
                data1.push_back(pRoot->val);
                s1.pop();
                result.push_back(data1);
               data1.clear();
               number=number+1;
            }*/
            
            if(s1.empty()||(number%2==0&&number!=2))
           
            {
                pRoot=s2.top();
                data2.push_back(pRoot->val);
                    s2.pop();
                if(s2.empty())
                {
                result.push_back(data2);
                    data2.clear();
                
                }
            }
            else 
            {
            pRoot=s1.top();
            data1.push_back(pRoot->val);
            s1.pop();
                if(s1.empty())
                {
                result.push_back(data1);
                  data1.clear();
                }
            }
            if((number%2==0))
            {
              
                if(pRoot->left!=NULL)
                {
                   s1.push(pRoot->left);
                }
               
                if(pRoot->right!=NULL)
               {
                   s1.push(pRoot->right);
               }
                num1++;
       if(num1==pow(2,(number-2)))
       {
            number++;
          num1=0;
           continue;
       }
                else
                {
               continue;
                }
            }
            if(number%2==1)
            {
                   temp=1;
                if(pRoot->right!=NULL)
                {
                    s2.push(pRoot->right);
                }
                if(pRoot->left!=NULL)
                {
                    
                    s2.push(pRoot->left);
                }

        num2++;
            if(num2==pow(2,(number-2)))
                {
                number++;
                num2=0;
                continue;
            }
        else{
            continue;
        }
        } 
       
              }
       return result;
    }
     
    
    
};
