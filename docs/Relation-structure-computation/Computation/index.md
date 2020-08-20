# 关于本章

本章讨论“Computation on discrete objects“。

## Computation on discrete objects

### 计算思维

在`index.md`中，我们已经总结了discrete objects的computable的特性，那如何来实现Computation 呢？当我们开始思考“Computation on discrete objects”的时候，其实就已经萌发了“计算思维”，即开始思考“哪些问题是可计算的？”、“该如何实现计算”。

#### 如何设计algorithm

- 对于discrete objects，分析其结构，找出relation，给出formal definition，那么我们就设计algorithm，对其进行计算
- 基于discrete objects的relation、structure来设计algorithm

#### 该如何实现计算: one-by-one

下面是两种非常重要的computation形式：

- iteration
- recursion

后面我们将上述两种computation形式统称为“**one-by-one computation**”，很多的algorithm都是基于上述两种形式。

**one-by-one computation的直观理解：**

- 基于discrete objects的relation、structure来设计algorithm，algorithm采用one-by-one computation

- one-by-one是沿着structure、relation逐个进行处理，它和optional sub structure密切相关。

- 所有的one-by-one的，都是enumerable、countable。



##### relation and recursion

同一个relation、transitive relation、的structure，往往是recursive的，可以进行递归定义了，可以使用structural recursion来进行解决。

什么样的关系可以形成什么样的结构。比如chain、tree、graph。

什么样的关系可以使用recursion来进行处理。



#### 哪些问题是可计算的？

Turing的可计算理论是对此的研究，下面是一些想法:

- 再复杂的问题也需要转换为one-by-one的方式来进行计算，即使复杂如back-prop也是如此，通过度量computation的量，可以计算得到算法复杂度

### 离散和图灵机

Turing-machine的computation也是one-by-one。



### recursive definition and discrete

任何recursive definition，都是离散的，都可以进行计算



### 函数的执行是离散的

名称中的sub，表示去具备包含关系。

将函数抽象成一个一个的节点，则我们所描述的是一张图。

显然它是具备离散特性的。

它的执行模型是离散的

### CPU对指令的执行是离散的

CPU的指令的执行是一条一条的，它是离散的

### abstract machine

#### stack machine

显然是离散的

#### Turing machine

Turing machine也是one-by-one地执行的，所以它是离散的



## Book 《Discrete Computational Structures》

https://books.google.com/books/about/Discrete_Computational_Structures.html?id=KrLiBQAAQBAJ&source=kp_book_description

https://www.elsevier.com/books/discrete-computational-structures/korfhage/978-0-12-420850-6