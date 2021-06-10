![](https://img.shields.io/codacy/grade/34055444cb164f28ab2f3978a73cab56?style=flat-square)
![](https://img.shields.io/tokei/lines/github/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/license/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/commit-activity/m/MarioSieg/NominaxRuntime)

# Corium Programming Language

Corium is a modern scripting language for all platforms.<br>
The goal is to have a safe, clean and easy to write scripting language,<br>
which is still very fast, so it can be used for AI, HPC or game development.<br>
The final features of the language are:<br><br>

* Easy to learn
* Clean syntax
* Safe, statically typed
* Test driven development
* Fast prototyping
* Parallel keyword for automatic parallelism
* Offload keyword for automatic GPGPU
* Cross-platform development
* Builtin formatter
* Builtin package installer
* Fast

The source code for the language parser is in the [Corium](https://github.com/MarioSieg/Corium/tree/master/Corium) directory.

<h2> Why another language? </h2>

As you might know,<br>
there are already plenty of programming languages out there.<br>
Many programming can be divided into two groups (the so called two language problem):<br>
There are very hight level languages such as Python or Java and<br>
many performance critical code is written in a more lower level language <br>
such as C, C++ or Rust. This is highly inefficient as it requires more knowledge,<br>
testing and time. It is also more error prone.<br>
Corium allows for code which is clean, portable, easy to write and still very fast.<br>
This might sound like the "Julia" language, but Corium relies much more on simplicity.<br>
With a semicolon free, easy to read C like syntax, it's easy to learn the language.<br>
The core language features are enough to write good code, but not too much to become bloated.<br>
It has a great and easy to use debugger, package manager and linter.<br>
Just get your favourite editor like VisualStudioCode, IntelliJ or something else,<br>
and start coding!<br>
It's also fairly easy to embed Corium into an existing C++ application.<br>
Corium also is used as a game scripting language in one of my custom engines.<br>

<h2> What's the current state of Corium? </h2>
Corium is currently under heavy development.<br>
Nominax (the runtime system) is ready for simple Corium programs.<br>
The primary focus lies on the frontend language lexer and code generator.<br>
In some weeks, it is expected to have a first working version,<br>
which can be used to write simple code in Corium.<br>
This is a big step, from that point on features will come in quickly.<br>
That's why we need you!<br>
Consider to contribute or sponsor the project!<br>
Let's make Corium a widely used, beginner friendly and fast language!<br>

<h2> Nominax Runtime </h2>
<h4>
Nominax is the runtime environment for Corium.<br>
It supports heavy parallelism, JIT compiling and garbage collection out of the box.<br>

The source code is in the [Nominax](https://github.com/MarioSieg/Corium/tree/master/Nominax) directory.
For more technical information, check out the Nominax [ReadMe](https://github.com/MarioSieg/Corium/blob/dev/Nominax/README.md).
</h4>

<h2> Roadmap </h2>

[Trello Board](https://trello.com/b/QiBdAQrb/nominax)

# Corium To-Go :coffee:
<h2>Short cheat sheet for the basics</h2>

<h3> Primitive Data Types </h3>
There are 5 primitive data types in Corium:<br>

* int
* float
* bool
* char

The number types ```int``` and ```float```<br>
are 64 bits wide and provide enough range and precision for all tasks.<br>
Corium empowers static typing for safety and explicit code,<br>
and choosing the type is very simple.<br>
Every of the 4 primitive type is perfect for<br>
some specific type of data.<br>

<h4>int</h4>

* A 64-bit signed integer.
* Can hold values from -9223372036854775808 to 9223372036854775807.
* Because it it signed, it can also hold negative values.
* This type is used as the default type for natural number calculations.
* The equivalent in other C style languages is “long”.

<h4>float</h4>

* 64-bit double precision float.
* Can hold values from -2.22507•10−308  to approximately 1.79769•10308.
* This type is used as the default type for real number calculations.
* The equivalent in other C style languages is "double".

<h4>bool</h4>

* A boolean type.
* Can either be true (1) or false (0).

<h4>char</h4>

* A 32-bit UTF-32 character.
* Can hold **any** unicode codepoint.

<h3>Local Variables</h3>
We've just learned the primitive data types.
In Corium, local variables are declared by the follow scheme:

```
let <VariableName> <Type?> = <Literal?>
```
Let's create some local variables using the
```let```
keyword. No semicolons required!<br>

```
let a int = 3
let b float = 2.5
let c char = 'O'
let d bool = true
```
If you look at the above scheme again,<br> the ```Type```
and the ```Literal```
are optional (indicated by the
```?```).<br> That means that we can elide them:

```
let a = 3
let b = 2.5
let c = 'O'
let d = true
```

That's better right?<br>
Corium knows the type from the literal,
so types can be deduced:
| Literal  | Deduced Type |
| ------------- | ------------- |
| 3  | int  |
| 2.5  | float  |
| 'O'  | char  |
| true  | bool  |

<h3> Functions And Methods </h3>
Like in many other languages,
every program starts in within the

```Main```
function.
So let's follow the tradition and start with hello world:

```
main () {
    print("Hello, World")
}
```

Methods and functions are declared by the following scheme:

```
<FunctionName> ( <Parameters> ) <ReturnType> {

}
```

Let's write a function which takes no parameters and returns nothing:

```
sayHello () {
    print("Say hello to my little friend!")
}
```

in C we would write this function like this:

```
void sayHello () {
    printf("Say hello to my little friend!\n");
}
```

this also applies to many other languages deriving from C such as C++, Java or C#,<br>
but of course the priting mechanism is different.<br>
Lets write another functions which returns a number:<br>

```
getNumber () int {
    return 5
}
```

Let's write it again in C:

```
int getNumber() {
    return 5;
}
```

As you can see, the return type is just at a different position and there are no semicolons.<br>
If your functions returns nothing, the return type is just elided.<br>
There is no need to write ```void``` like we know it from C style languages.<br>

More comming soon...
