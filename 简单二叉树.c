/*
 *前序、后序、中序变量二叉树（递归解法）
 *中序 栈实现
 *深度遍历 队列实现
 *应用：二叉树镜像（剑指offer）
 */
 
 typedef struct BiTNode *BiTree;//结点指针
 
 //前序遍历
 void preOrderTraverse(BiTree T)
 {
	 if(NULL == T)
		 return;
	 printf("%c", T->data);
	 preOrderTraverse(T->lchild);
	 preOrderTraverse(T->rchild);
	 
	 return;
 }
 
 //中序遍历
 void midOrderTraverse(BiTree T)
 {
	 if(NULL != T)
	 {
		 midOrderTraverse(T->lhild);
		 printf("%c", T->data);
		 midOrderTraverse(T->rchild);
	 }
	 
	 return;
 }
 
 //后序遍历
 void postOederTraverse(BiTree T)
 {
	 if(NULL != T)
	 {
		 postOederTraverse(T->lchild);
		 postOederTraverse(T->rchild);
		 printf("%c",T->data);
	 }
	 return;
 }
 
/*
 *中序非递归实现 栈实现
 *栈使用数字实现，存储单元是结点指针
 *双重循环：外面判断栈、当前结点是否空；
 *          里面的循环每次把所有左结点入栈（注意溢出检查）
 *          接着栈顶元素出栈打印，并把有子树入栈
 */
 void midOrder(BiTree T)
 {
	 if(NULL == T)
		 return ;
	 struct BiTNode* st[maxlen+1];//指针数组
	 
	 int top = 0;
	 
	 do{
		 while(T)
		 {
			 if(top == maxlen)
				 exit(OVERFLOW); //栈顶指针防止溢出
			 st[++top] = T;      //当前结点所有左节点入栈
			 T = T->lchild;
		 }
		 
		 if(top)
		 {
			 t = st[top--];//指针出栈
			 printf("%c", t->data);
			 t->rchild;    //同时右孩子结点置为当前结点
		 }
	 }while(0 != top || NULL != T ) //父节点未访问或者右孩子未遍历完
	
	return ;
 }
 
 //二叉树镜像
 void mirrorRecursively(BiTree *pNode)
 {
	 if(NULL == pNode)
		 return;
	 if(NULL == pNode->lchild && NULL ==pNode->rchild)
		 return;
	 
	 BiTNode *tem = pNode->lchild;
	 pNode->lchild = pNode->rchild;
	 pNode->rchild = tem;
	 
	 if(NULL ！= pNode->lchid)
		 mirrorRecursively(pNode->lchid);
	 if(NULL != pNode->rchild)
		 mirrorRecursively(pNode->rchild);
 }