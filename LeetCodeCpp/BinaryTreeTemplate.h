#pragma once






//元编程侧重点在于「用代码生成代码」，泛型编程侧重点在于「减小代码对特定数据类型的依赖」。
//碰巧这两件事 C++ 的模板都可以干。

//当今各种编程语言, 相比于90年代, 就干了两件事:

//1.把本该发生在编译阶段的一些工作挪到运行期
//2.把本该发生在运行阶段的一些工作挪到编译期

//这两个方向分别代表着两种思维方式, 即更自由还是更高性能. 
//1.的代表就是各种动态编译的脚本语言, 而2在我看来最典型的代表就是C++的模板元编程了,
//但其实, 模板元编程对大多数人来说确实用处不大, 因为性能在今天对于大多数人已经不是最重要的了,但是, 毕竟有一些情况我们还是需要性能的.



//模板元编程：用四个字概括:操纵类型

//但是在C++中，值是受到歧视的。最简单的，我们不能用值重载。我们只能用劣质标签来匹配。但是我们可以用值来做模板参数
//（这是C++模板最重要的特性之一）。所以我们有Int Wrapper，用模板来把int包起来，这样我们就可以像使用类型一样使用值了。


//这就是一个接受类型（Template-Args）并返回类型（Type）的函数啊！在模板元编程中我们称呼这个东西为“元函数”
//理解元函数就基本上理解模板元编程要干什么了。你有可能觉得模板元编程很弱欸，就这么个东西能图灵完备？
//当然了，因为我们还有偏特化（分支语句）和递归（循环语句），我们可以随意自如的处理类型。

//template <Template - Args>
//struct Function
//{
//	using Type = ...;
//};

//说到这，你还是不服，就几个破类型，YourClass，int，double，Int<N>，你还能给我玩出花来？ 我们可以Cons<A, Cons<B, Cons<...>>>无穷无尽也。
template <typename A, typename B>
struct Cons
{
	using Car = A;
	using Cdr = B;
};
//有了Cons，就有了一切。二生三，三生万物。Cons就是二，那二怎么生三呢？简单：
template <typename K, typename L, typename R>
using TreeNode = Cons<K, Cons<L, R>>;
//有了线性结构、树状结构，有了偏特化、递归，我们为所欲为。

//有了这些基础，我们再来体会一下高级的类型操纵。最简单的就是量纲分析了，量纲分析是《模板元编程》的开篇例子。
//模板元编程还有很多应用场景。所有你需要存储、操纵、搜索类型的地方，都是模板元编程的用武之地。



//模板的递归
//template<int count>
//class Copy
//{
//public:
//	static inline go(float* const out, float* const in, int i)
//	{
//		//这里递归
//		Copy<count - 1>::go(out, in, i);
//		out[count][i - 1] = in[count][i];
//	}
//};
//
//template<>
//class Copy<0>
//{
//public:
//	static inline go(float* const, float* const, int)
//	{}
//};

//先定义一个模板类，然后根据情况初始化不同的类
template<class ValType>
class BinaryTnode
{
public:
	ValType value;
	//friend class BinaryTree<ValType>;

};


//二叉树模板
class BinaryTreeTemplate
{
	//friend class BinaryTree<ValType>;

};
//#include "stack.cpp"

