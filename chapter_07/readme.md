### 折半查找的实现

![01.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/01.png)



![02.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/02.png)



![03.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/03.png)

折半查找的判定树一定是平衡二叉树

折半查找的判定树中，==只有最下面一层是不满的==，应此，元素个数为n时==树高h\=$log_2{(n+1)}$==

判定树结点关键字：左<中<右，满足二叉排序树的定义

失败结点：n+1个（等于成功结点的空链域数量）

> 在二叉树中，n个结点有2n个链域，不空的链域为树的度的总和n-1，那么空的链域即为n+1个



==树高h\=$log_2{(n+1)}$==

查找成功的ASL<= h      查找失败的ASL<= h

折半查找的时间复杂度=$O(log_2{n})$ 



![04.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/04.png)



### B树

![05.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/05.png)



![06.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/06.png)



![07.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/07.png)



![08.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/08.png)



![09.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/09.png)



![10.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/10.png)



![11.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/11.png)



![12.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/12.png)



![13.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/13.png)



![14.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/14.png)



### B+树

![15.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/15.png)



![16.png](https://github.com/katoluo/DataStructures/raw/master/chapter_07/images/16.png)





