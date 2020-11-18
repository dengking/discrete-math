# Ordering

对于无序、混乱、不可重复、随机、二义性，这些是需要克服的，需要programmer进行显式的控制。只有有序才能够实现computation，才能够实现可靠性。

> NOTE: "显式的控制"可以从control-theory来进行分析，角度是: 加入control以使之有序，从而是computational的。

下面是一些例子:

1) TensorFlow `tf.control_dependencies`

在阅读TensorFlow whitepaper的时候，其中有这样的描述:

> Our implementation also sometimes inserts **control dependencies** to enforce **orderings** between otherwise independent operations as a way of, for example, controlling the peak memory usage.

参见工程machine-learning。

2) memory barrier

参见工程parallel-computing

3) Ordering in distributed system

参见工程parallel-computing



## Ordering的维度

基于空间维度

基于时间维度
