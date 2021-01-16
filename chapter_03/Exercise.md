

















2. 算法设计题

（1）将编号为 0 和 1 的两个栈存放于一个数组空间 V[m]中,栈底分别处于数组的两端。当第 0 号栈的栈顶指针 top[0]等于-1 时该栈为空,当第 1 号栈的栈顶指针 top[1]等于 m 时该栈为空。两个栈均从两端向中间增长。试编写双栈初始化,判断栈空、栈满、进栈和出栈等算法的函数。双栈数据结构的定义如下:

```c
typedef struct
{
    int top[2], bot[2];    // 栈顶和栈底指针
    SElemType *V;          // 栈数组
    int m;                 // 栈最大可容纳元素个数
} DblStack;
```

![图3_17.png](https://github.com/katoluo/DataStructures/raw/master/chapter_03/images/%E5%9B%BE3_17.png)

<center>图3.17	双栈结构的表示<center/>
​	

​	[来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/01)

（2）回文是指正读反读均相同的字符序列,如“abba”和“abdba”均是回文,但“good”不是回文。试写一个算法判定给定的字符向量是否为回文。(提示:将一半字符入栈)

​	[来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/02)

（3）设从键盘输入一整数的序列：$a_1,a_2,a_3,...,a_n,$ 试编写栓法实现: 用栈结构存储输入的整数，当$a_i \neq -1$ 时，将$a_i$进栈；当$a_i = -1$时，输出栈顶整数并出栈。算法应对异常情况（入栈满等）给出相对应的信息。

​	[来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/03)

（4）从键盘上输入一个后缀表达式，试编写算法计算表达式的值。规定：逆波兰表达式的长度不超过一行，以"$"作为输入结束，操作数之间用空格分隔，操作符只可能有+、-、*、/四种运算。例如：234 34 + 2 *\$。

​	[有关后缀表达式的理解](https://blog.csdn.net/summerxiachen/article/details/77073320?utm_medium=distribute.pc_relevant.none-task-blog-OPENSEARCH-4.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-OPENSEARCH-4.control#commentBox)

​	[来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/04)

（5）假设以 I 和 O 分别表示入栈和出栈操作。栈的初态和终态均为空,入栈和出栈的操作序列可表示为仅由 I 和 O 组成的序列,称可以操作的序列为合法序列,否则称为非法序列。

- 下面所示的序列中哪些是合法的?

  A. IOIIOIOO	B. IOOIOIIO	C. IIIOIOIO	D. IIIOOIOO

- 通过上一问的分析,写出一个算法,判定所给的操作序列是否合法。若合法,返回 true,否则返回 false(假定被判定的操作序列已存入一维数组中)。

  [来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/05)

（6）假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意：不设头指针），试编写相应的置空队列、判断队列是否为空、入队和出队等算法。

​	[来自我的愚昧的答案](https://github.com/katoluo/DataStructures/tree/master/chapter_03/06)



