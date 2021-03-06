# 关于本章

在前面章节已经介绍了repetition，本章对它进行详细描述。

下面是实现repetition("重复执行某个computation")的两种方式：

- iteration
- recursion



## 无处不在的repetition

### Traverse on structure

参见`Relation-structure-computation\Structure\Computation-on-structure`章节。



## Recursion and functional programming

在functional programming一般使用recursion来实现repetition，关于此，在下面文章中有描述:

infogalactic [Recursion (computer science)](https://infogalactic.com/info/Recursion_(computer_science))

> Some [functional programming languages](https://infogalactic.com/info/Functional_languages) do not define any looping constructs but rely solely on recursion to repeatedly call code. 

infogalactic [Functional programming](https://infogalactic.com/info/Functional_programming)

> [Iteration](https://infogalactic.com/info/Iteration) (looping) in functional languages is usually accomplished via [recursion](https://infogalactic.com/info/Recursion). [Recursive functions](https://infogalactic.com/info/Recursion_(computer_science)) invoke themselves, allowing an operation to be performed over and over until the [base case](https://infogalactic.com/info/Recursion_(computer_science)) is reached. 



## Iteration VS recursion

两种都能够实现repetition。

Iteration的实现依赖于Iteration statements

> NOTE: 关于Iteration statements，参见:
>
> 1) C++: cppreference [Iteration statements](https://en.cppreference.com/w/cpp/language/statements#Iteration_statements)
>
> 2) Python: 
>
> 8.3. The `for` statement[¶](https://docs.python.org/3/reference/compound_stmts.html#the-for-statement)
>
> 8.2. The `while` statement[¶](https://docs.python.org/3/reference/compound_stmts.html#the-while-statement)
>
> 

Recursion的实现依赖于recursive function

当所处的环境无法使用Iteration statements的时候，则只能够通过Recursion来实现repetition: 

1) 有的programming language并没有提供iteration statement，比如Lisp，因此，它们只能使用recursion来实现repetition。

2) C++ TMP

