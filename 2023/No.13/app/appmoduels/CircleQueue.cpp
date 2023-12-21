#include "CircleQueue.h" 
#include <qdebug.h> 

CircleQueue::CircleQueue()
{
	int s = 8; //默认的队列容量为8 
}
CircleQueue::~CircleQueue() {}

/*初始化循环队列*/
void CircleQueue::InitCircleQueue()
{
	queuerear = 0;
	queuefront = 0;
}
/*清空循环队列*/
void CircleQueue::CleanQueue()
{
	queuerear = 0;
	queuefront = 0;
}
/*能否获取循环队列头*/
bool CircleQueue::QueueHead(CircleQueuenode* elem)
{
	if (queuerear == queuefront) {
		qDebug() << "queue is empty can not get" << endl;
		return false;
	}
	elem = array[queuerear];
	return true;
}
/*判断循环队列是否为空*/
bool CircleQueue::EmptyQueue()
{
	return (queuerear == queuefront) ? true : false;
}
/*清空循环队列*/
bool CircleQueue::FullQueue() {
	if ((queuefront + 1) % 8 == queuerear)
		return true;
	else
		return false;
}
/*循环队列入队*/
bool CircleQueue::EnQueue(CircleQueuenode* elem)
{

	array[queuefront++] = elem;
	if (queuefront >= 8) {
		queuefront = 0;
	}
	return true;
}
/*循环队列出队*/
bool CircleQueue::DeQueue(CircleQueuenode* elem)
{
	elem = array[queuerear++];
	if (queuerear >= 8)
		queuerear = 0;
	return true;
}
/*获取循环队列长度*/
int CircleQueue::QueueLength()
{
	return  (queuefront - queuerear + 8) % 8;
}
/*获取循环队列头*/
int CircleQueue::getQueuefront()
{
	return  queuefront;
}
/*获取循环队列尾*/
int CircleQueue::getQueuerear()
{
	return queuerear;
}

/*获取循环队列某位置元素*/
CircleQueuenode* CircleQueue::at(int i)
{
	return array[i];
}