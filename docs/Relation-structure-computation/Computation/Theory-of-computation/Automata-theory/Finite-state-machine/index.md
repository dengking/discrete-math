# [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine)

> TIPS: In Chinese, [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine) means 有穷自动机

A **finite-state machine** (**FSM**) or **finite-state automaton** (**FSA**, plural: *automata*), **finite automaton**, or simply a **state machine**, is a mathematical [model of computation](https://en.wikipedia.org/wiki/Model_of_computation). It is an [abstract machine](https://en.wikipedia.org/wiki/Abstract_machine) that can be in exactly one of a finite number of *states* at any given time. The FSM can change from one state to another in response to some external [inputs](https://en.wikipedia.org/wiki/Input_(computer_science)) and/or a condition is satisfied; the change from one state to another is called a *transition*.[[1\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-1) An FSM is defined by a list of its states, its initial state, and the conditions for each transition. Finite state machines are of two types:

- [deterministic finite state machines](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) 
- [non-deterministic finite state machines](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton).[[2\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-2) 

A deterministic finite-state machine can be constructed equivalent to any non-deterministic one.

The behavior of state machines can be observed in many devices in modern society that perform a predetermined sequence of actions depending on a sequence of events with which they are presented. Simple examples are [vending machines](https://en.wikipedia.org/wiki/Vending_machine), which dispense products when the proper combination of coins is deposited, [elevators](https://en.wikipedia.org/wiki/Elevator), whose sequence of stops is determined by the floors requested by riders, [traffic lights](https://en.wikipedia.org/wiki/Traffic_light), which change sequence when cars are waiting, and [combination locks](https://en.wikipedia.org/wiki/Combination_lock), which require the input of a sequence of numbers in the proper order.

> TIPS: The state machine can do much more, see [Usage](#Usage) for more detail.

The **finite state machine** has less computational power than some other models of computation such as the [Turing machine](https://en.wikipedia.org/wiki/Turing_machine).[[3\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-Belzer-3) The computational power distinction means there are computational tasks that a Turing machine can do but a FSM cannot. This is because a FSM's [memory](https://en.wikipedia.org/wiki/Computer_memory) is limited by the number of states it has. FSMs are studied in the more general field of [automata theory](https://en.wikipedia.org/wiki/Automata_theory).

> TIPS:  [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) operates on an infinite memory.

> TIPS: There is an incomplete hierarchy in terms of powers of different types of abstract machines in page [automata theory](https://en.wikipedia.org/wiki/Automata_theory)



## Concepts and terminology

A *state* is a description of the status of a system that is waiting to execute a *transition*. A transition is a set of actions to be executed when a condition is fulfilled or when an **event** is received. For example, when using an audio system to listen to the radio (the system is in the "radio" state), receiving a "next" stimulus results in moving to the next station. When the system is in the "CD" state, the "next" stimulus results in moving to the next track. Identical stimuli trigger different actions depending on the current state.

In some finite-state machine representations, it is also possible to associate actions with a state:

- an entry action: performed *when entering* the state, and
- an exit action: performed *when exiting* the state.

## Representations

- [state transition table](https://en.wikipedia.org/wiki/State_transition_table)  
- [UML state machines](https://en.wikipedia.org/wiki/UML_state_machine)  
- [SDL state machines](https://en.wikipedia.org/wiki/Specification_and_Description_Language)
- [State diagram](https://en.wikipedia.org/wiki/State_diagram)

## Classification

 **Finite state machines** can be subdivided into 

- transducers（转换器）
- acceptors
- classifiers
- sequencers.[[6\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-6) 



### Acceptors (recognizers)

**Acceptors** (also called **recognizers** and **sequence detectors**), produce **binary output**, indicating whether or not the received input is accepted. Each state of an FSM is either "accepting" or "not accepting". Once all input has been received, if the current state is an **accepting state**, the input is accepted; otherwise it is rejected. As a rule, input is a [sequence of symbols](https://en.wikipedia.org/wiki/String_(computer_science)) (characters); actions are not used. The example in figure 4 shows a finite state machine that accepts the string "nice". In this FSM, the only **accepting state** is state 7.

> TIPS: In machine learning terms, it's a dichotomy.

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a8/Fsm_parsing_word_nice.svg/220px-Fsm_parsing_word_nice.svg.png)

Fig. 4 Acceptor FSM: parsing the string "nice" 

A (possibly infinite) set of symbol sequences, aka. formal language, is called a [regular language](https://en.wikipedia.org/wiki/Regular_language) if there is some **Finite State Machine** that accepts exactly that set. For example, the set of binary strings with an even number of zeroes is a **regular language** (cf. Fig. 5), while the set of all strings whose length is a prime number is not.

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/DFAexample.svg/220px-DFAexample.svg.png)

Fig. 5: Representation of a finite-state machine; this example shows one that determines whether a binary number has an even number of 0s, where *S*1 is an **accepting state**. 

A machine could also be described as defining a language, that would contain every string accepted by the machine but none of the rejected ones; that language is "accepted" by the machine. By definition, the languages accepted by FSMs are the [regular languages](https://en.wikipedia.org/wiki/Regular_language)—; a language is regular if there is some FSM that accepts it.

The problem of determining the language accepted by a given **finite state acceptor** is an instance of the [algebraic path problem](https://en.wikipedia.org/w/index.php?title=Algebraic_path_problem&action=edit&redlink=1)—itself a generalization of the [shortest path problem](https://en.wikipedia.org/wiki/Shortest_path_problem) to graphs with edges weighted by the elements of an (arbitrary) [semiring](https://en.wikipedia.org/wiki/Semiring).

> TIPS:  This passage reminds me of [regular expression](https://en.wikipedia.org/wiki/Regular_expression).

The start state can also be an accepting state, in which case the automaton accepts the empty string.

An example of an accepting state appears in Fig.5: a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) that detects whether the [binary](https://en.wikipedia.org/wiki/Binary_numeral_system) input string contains an even number of 0s.

*S*1 (which is also the start state) indicates the state at which an even number of 0s has been input. S1 is therefore an **accepting state**. This machine will finish in an **accept state**, if the binary string contains an even number of 0s (including any binary string containing no 0s). Examples of strings accepted by this DFA are [ε](https://en.wikipedia.org/wiki/Ε) (the [empty string](https://en.wikipedia.org/wiki/Empty_string)), 1, 11, 11…, 00, 010, 1010, 10110, etc.

### Classifiers

A **classifier** is a generalization of a finite state machine that, similar to an acceptor, produces a single output on termination but has more than two terminal states. 

> TIPS: In machine learning terms, it's a multi-class classifier.

### Determinism

A further distinction is between **deterministic** ([DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)) and **non-deterministic** ([NFA](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton), [GNFA](https://en.wikipedia.org/wiki/GNFA)) automata. In a deterministic automaton, every state has exactly one transition for each possible input. In a non-deterministic automaton, an input can lead to one, more than one, or no transition for a given state. The [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction) algorithm can transform any **nondeterministic automaton** into a (usually more complex) **deterministic automaton** with identical functionality.

A finite state machine with only one state is called a "combinatorial FSM". It only allows actions upon transition *into* a state. This concept is useful in cases where a number of finite state machines are required to work together, and when it is convenient to consider a purely combinatorial part as a form of FSM to suit the design tools.[[10\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-10)

## Mathematical model

In accordance with the general classification, the following formal definitions are found: 

- A *deterministic finite state machine* or *acceptor deterministic finite state machine* is a [quintuple](https://en.wikipedia.org/wiki/Tuple) $ (\Sigma ,S,s_{0},\delta ,F) $, where: 
  -  $ \Sigma $ is the input [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)) (a finite, non-empty set of symbols). 
  -  $ S $ is a finite, non-empty set of states. 
  -  $ s_{0} $ is an initial state, an element of $ S $. 
  -  $ \delta $ is the state-transition function: $ \delta :S\times \Sigma \rightarrow S $ (in a [nondeterministic finite automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton) it would be $ \delta :S\times \Sigma \rightarrow {\mathcal {P}}(S) $, i.e., $ \delta $ would return a set of states). 
  -  $ F $ is the set of final states, a (possibly empty) subset of $ S $. 

For both deterministic and non-deterministic FSMs, it is conventional to allow $ \delta $ to be a [partial function](https://en.wikipedia.org/wiki/Partial_function), i.e. $ \delta (q,x) $ does not have to be defined for every combination of $ q\in S $ and $ x\in \Sigma $. If an FSM $ M $ is in a state $ q $, the next symbol is $ x $ and $ \delta (q,x) $ is not defined, then $ M $ can announce an error (i.e. reject the input). This is useful in definitions of general state machines, but less useful when transforming the machine. Some algorithms in their default form may require **total functions**.

A **finite state machine** has the same computational power as a [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) that is restricted such that its head may only perform "read" operations, and always has to move from left to right. That is, each formal language accepted by a finite state machine is accepted by such a kind of restricted Turing machine, and vice versa.[[15\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-15)

> TIPS: We can conclude that [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) is an generalization of **finite state machine** or **finite state machine** is a restrictive version of  [Turing machine](https://en.wikipedia.org/wiki/Turing_machine).



## Optimization

 *Main article:* [DFA minimization](https://en.wikipedia.org/wiki/DFA_minimization) 

Optimizing an FSM means finding a machine with the minimum number of states that performs the same function. The fastest known algorithm doing this is the [Hopcroft minimization algorithm](https://en.wikipedia.org/wiki/DFA_minimization#Hopcroft's_algorithm).[[17\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-17)[[18\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-18) Other techniques include using an [implication table](https://en.wikipedia.org/wiki/Implication_table), or the [Moore reduction procedure](https://en.wikipedia.org/wiki/Moore_reduction_procedure). Additionally, acyclic FSAs can be minimized in linear time.[[19\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-19) 



## Usage

In addition to their use in modeling **reactive systems** presented here, **finite state machines** are significant in many different areas, including [electrical engineering](https://en.wikipedia.org/wiki/Electrical_engineering), [linguistics](https://en.wikipedia.org/wiki/Linguistics), [computer science](https://en.wikipedia.org/wiki/Computer_science), [philosophy](https://en.wikipedia.org/wiki/Philosophy), [biology](https://en.wikipedia.org/wiki/Biology), [mathematics](https://en.wikipedia.org/wiki/Mathematic), and [logic](https://en.wikipedia.org/wiki/Logic). Finite state machines are a class of automata studied in [automata theory](https://en.wikipedia.org/wiki/Automata_theory) and the [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation). In computer science, finite state machines are widely used in modeling of application behavior, design of [hardware digital systems](https://en.wikipedia.org/wiki/Digital_electronics), [software engineering](https://en.wikipedia.org/wiki/Software_engineering), [compilers](https://en.wikipedia.org/wiki/Compiler), [network protocols](https://en.wikipedia.org/wiki/Network_protocol), and the study of computation and languages. 

### Software applications

The following concepts are commonly used to build software applications with finite state machines: 

- [Automata-based programming](https://en.wikipedia.org/wiki/Automata-based_programming)
- [Event-driven finite-state machine](https://en.wikipedia.org/wiki/Event-driven_finite-state_machine)
- [Virtual finite-state machine](https://en.wikipedia.org/wiki/Virtual_finite-state_machine)
- [State design pattern](https://en.wikipedia.org/wiki/State_pattern)
- [State machine replication](https://en.wikipedia.org/wiki/State_machine_replication)
- [Regular expression](https://en.wikipedia.org/wiki/Regular_expression)

### Finite state machines and compilers

Finite automata are often used in the [frontend](https://en.wikipedia.org/wiki/Compilers#Front_end) of programming language compilers. Such a frontend may comprise several finite state machines that implement a [lexical analyzer](https://en.wikipedia.org/wiki/Lexical_analysis) and a parser. Starting from a sequence of characters, the lexical analyzer builds a sequence of language tokens (such as reserved words, literals, and identifiers) from which the parser builds a syntax tree. The lexical analyzer and the parser handle the regular and context-free parts of the programming language's grammar.[[22\]](https://en.wikipedia.org/wiki/Finite-state_machine#cite_note-22) 