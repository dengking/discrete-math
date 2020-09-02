# N queen

## 问题描述

在`n*n`的棋盘上放置`n`个皇后，任何两个皇后彼此不受攻击。

根据国际象棋规定：皇后可以攻击放在同一行、同一列、同一斜线上的其他皇后。

斜线是指斜率为$+-1$的斜线。

## 算法设计

### 解的表示

对于`n*n`的棋盘，我们自然而然地想到使用`n*n`二维数组来表示，皇后所处的位置可以使用二维数组的坐标来表示，二维数组的坐标定义如下：

其行号从上到下、列号从左到右，编号依次为$1,2,\dots, n$。

那如何来记录问题的解，即皇后在棋盘上的位置呢？皇后的位置肯定是由$(x, y)$坐标组成的对，所以对于问题的解，我们可以采取如下的方式：

- `std::vector<std::pair<int, int>>` 使用 `std::pair<int, int>` 来表示坐标
- 用`n`元组`x[1:n]`表示问题的解，`x[i]`表示皇后`i`放在棋盘的第`i`行的第`x[i]`列上。

相比于方式一，方式二是更加紧凑、节省空间的，它使用下标来表示行号，对应的数组值来表示列号。所以后面的描述采用方式二。

### 限制条件

#### 限制条件1

不允许将2个皇后放在同一列，下面给出两个皇后$i$、$j$位于同一列的条件:
$$
x[i] == x[j]
$$


#### 限制条件2

不允许将2个皇后放在同一斜线，根据斜率的定义，下面给出了两个皇后$i$、$j$位于同一斜线的条件:
$$
|{\frac {x[i] - x[j] } {i -j}} | = 1
$$


### 回溯法

用回溯法解n后问题时，使用完全`n`叉树来表示解空间。

上述的可行性约束由函数`Place`实现。

递归函数`Backtrack(1)`实现对整个解空间的回溯搜索，`Backtrack(i)`搜索解空间中第`i`层子树。

在`Backtrack`中：

- 当`i>n` 时，算法搜索到了**叶节点**，遂得到了一个完整解

- 当$i <= n $ 时，**当前扩展节点`Z`**是解空间中的**内部节点**，该节点有$x[i]=1,2, \dots, n$ ，共`n`个子节点。对**当前扩展节点`Z`**的每个子节点，由`Place`检查其可行性：
  - 如果可行，则递归地对**子树**进行搜索
  - 如果不可行，则剪枝，即减去不可行的子树



## Implementation

### Backtrack by recursion

```C++
class Queen
{
    friend int nQueen(int);
    private:
    int m_N; // 棋盘的大小
    int *m_X; // 解
    int m_Sum; // 解的数量
    private:
    /**
    * 检查皇后k的位置是否满足可行性约束
    */
    bool Place(int k)
    {
        // 检查k前面已经放置的皇后
        for(int j=1; j<k; ++j)
        {
            // 检查两个约束条件
            if(abs(k-j) == abs(x[j] - x[k]) || x[j] == x[k])
            {
                // 不满足约束条件
                return false;
            }
        }
        return true;
    }
    void Backtrack(int t)
    {
        if(t>m_N)
        {
            m_Sum ++;
        }
        else
        {
            for(int i=1;i<m_N;++i)
            {
                m_X[t] = i;
                if(Place(t))
                {
                	Backtrack(t+1);  
                }
            }
        }
    }
};

int nQueen(int n)
{
    Queen q;
    q.m_N = n;
    q.m_Sum = 0;
    int* p = new int[n+1]();
    q.m_X = p;
    q.Backtrack(1);
    delete [] p;
    return q.m_Sum;
}

int main()
{
    nQueue(5);
}
// g++ test.cpp
```





### Backtrack by iteration

数组`m_X`记录了解空间树中从**根节点**到**当前扩展节点`Z`**的路径，这些信息已经包含了回溯法在回溯时所需要的信息。利用数组`m_X`所包含的信息，可以将上述回溯法使用非递归方式来进行实现，进而省去$O(n)$递归栈空间。

```c++

void Backtrack()
{
	m_X[1] = 0;
    int k = 1; // k表示第k个皇后
    while(k > 0)
    {
        m_X[k] += 1; // 
        /** 
        * 下面这个while循环实现的是：给皇后k寻找一个符合约束条件的位置，寻找的结果有：
        * - 找到了符合条件的位置：则退出循环的时候m_X[k]<=n
        * - 没有符合条件的位置：则退出循环的时候m_X[k] > n
        * 所以根据m_X[k]的值，可以判断对于皇后k，是否找到了符合约束条件的位置
        */
        while( (m_X[k] <= m_N) && !(Place(k)) ) 
        {
            m_X[k] += 1;
        }
        // 找到了符合条件的位置
        if(m_X[k] <= n)
        {
            // 得到了一个完整的解，需要注意的是，得到完整解后，并没有修改k的值，
            // 这就保证了和Backtrack by recursion中的顺序是相同的，即：
            // 它会将底层的所有可能性尝试完成后，再回溯到上一层，然后再深入到下一层。
            if(k == m_N)
            {
                m_Sum ++;
            }
            // 解还不完整
            else
            {
                // 深入
                k++;
                m_X[k] = 0; // 初始化下一个皇后的初始化位置
            }
        }
        // 没有找到符合条件的位置
        else
        {
            // 回溯
            k--;
        }
    }
}
```

#### 搜索顺序

上述算法的实现是非常精妙的，它对**解空间树**的搜索顺序和Backtrack by recursion中的顺序是相同的，这种顺序的**一致性**非常重要，我们将这种顺序成为**回溯法搜索顺序**，准确来说是：树的**先序遍历**。

下面是关于这种搜索顺序的感性认知:

- 它会将底层的所有可能性尝试完成后，再回溯到上一层，然后再深入到下一层。

结合代码来进行分析:

```c++
			// 得到了一个完整的解，需要注意的是，得到完整解后，并没有修改k的值，
            // 这就保证了和Backtrack by recursion中的顺序是相同的，即：
            // 它会将底层的所有可能性尝试完成后，再回溯到上一层，然后再深入到下一层。
            if(k == n)
            {
                m_Sum ++;
            }
```



#### 何时推出？

上述算法的退出条件是`while(k > 0)`，即当`k<=0`时，算法推出，那`k`何时会`<=0`呢？

其实有了前面的对搜索顺序的分析，再来看这个问题就不再难以理解了。我们的预期是：当算法将整个解空间树都遍历完成后，就退出执行。那现在来看，上述算法能否达到这个预期：

当`k == 1`、`m_X[k] == m_N`，表示已经完成了解空间树的搜索了，此时再来进入主循环体：

执行`m_X[1] += 1; //`， 则`m_X[1] == m_N + 1`，则不满足下面循环体的条件：

```c++
		while( (m_X[k] <= m_N) && !(Place(k)) ) 
        {
            m_X[k] += 1;
        }
```

则会进入如下分支:

```c++
// 没有找到符合条件的位置
        else
        {
            // 回溯
            k--;
        }
```

显然，经过上述代码后，`k == 0`，所以，就退出了主循环体，显然上述算法是符合预期的。
