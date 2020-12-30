//概述：用两个栈实现队列
//题目：队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

//解题思路：当stack2 中不为空时，在 stack2 中的栈顶元素是最先进入队列的元素，可以弹出。
//如果stack2为空时，我们把stack1中的元素逐个弹出并压入stack2。
//由于先进入队列的元素被压到stack1的底端，经过弹出和压入之后就处于stack2的顶端了，又可以直接弹出。

//时间复杂度：O(1) O(n)

template<typename T>
class CQueue
{
public:
    CQueue(){}
    ~CQueue(){}

    void appendTail(const T& node)
    {
        stackTail.push(node);
    }

    T deleteHead()
    {
        if (stackHead.empty())  
        {
            while (!stackHead.empty())
            {
                T& node = stackHead.top();
                stackHead.pop();
                stackTail.push(node);
            }
        }

        if (stackTail.empty())
            throw std::exception("queue is empty");
        
        T headNode = stackHead.top();
        stackHead.pop();
        return headNode;
    }

private:
    std::stack<T> stackTail;
    std::stack<T> stackHead;
};