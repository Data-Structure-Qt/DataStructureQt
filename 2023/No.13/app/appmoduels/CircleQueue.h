#include "CircleQueuenode.h" 
class CircleQueue
{
public:
	CircleQueue();    //默认的队列容量为8 
	~CircleQueue();
public:
	CircleQueuenode* at(int i); //队列位置的数据 
	void InitCircleQueue();//队列初始化 
	void CleanQueue();//清空队列  
	bool QueueHead(CircleQueuenode * elem);//取队头 
	bool EmptyQueue();//判断队列是否为空  
	bool FullQueue();//判断队列是否为满  
	bool EnQueue(CircleQueuenode * elem);//入队列 
	bool DeQueue(CircleQueuenode * elem);//出队列  
	int QueueLength();//返回长度  
	int getQueuefront();//返回头指针位置 
	int getQueuerear();//返回尾指针位置 
private:
	int queuerear = 0;
	int queuefront = 0;
	CircleQueuenode* array[8];//底层为数组 
};