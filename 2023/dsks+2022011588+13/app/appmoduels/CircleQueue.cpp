#include "CircleQueue.h" 
#include <qdebug.h> 

CircleQueue::CircleQueue()
{
	int s = 8; //Ĭ�ϵĶ�������Ϊ8 
}
CircleQueue::~CircleQueue() {}

/*��ʼ��ѭ������*/
void CircleQueue::InitCircleQueue()
{
	queuerear = 0;
	queuefront = 0;
}
/*���ѭ������*/
void CircleQueue::CleanQueue()
{
	queuerear = 0;
	queuefront = 0;
}
/*�ܷ��ȡѭ������ͷ*/
bool CircleQueue::QueueHead(CircleQueuenode* elem)
{
	if (queuerear == queuefront) {
		qDebug() << "queue is empty can not get" << endl;
		return false;
	}
	elem = array[queuerear];
	return true;
}
/*�ж�ѭ�������Ƿ�Ϊ��*/
bool CircleQueue::EmptyQueue()
{
	return (queuerear == queuefront) ? true : false;
}
/*���ѭ������*/
bool CircleQueue::FullQueue() {
	if ((queuefront + 1) % 8 == queuerear)
		return true;
	else
		return false;
}
/*ѭ���������*/
bool CircleQueue::EnQueue(CircleQueuenode* elem)
{

	array[queuefront++] = elem;
	if (queuefront >= 8) {
		queuefront = 0;
	}
	return true;
}
/*ѭ�����г���*/
bool CircleQueue::DeQueue(CircleQueuenode* elem)
{
	elem = array[queuerear++];
	if (queuerear >= 8)
		queuerear = 0;
	return true;
}
/*��ȡѭ�����г���*/
int CircleQueue::QueueLength()
{
	return  (queuefront - queuerear + 8) % 8;
}
/*��ȡѭ������ͷ*/
int CircleQueue::getQueuefront()
{
	return  queuefront;
}
/*��ȡѭ������β*/
int CircleQueue::getQueuerear()
{
	return queuerear;
}

/*��ȡѭ������ĳλ��Ԫ��*/
CircleQueuenode* CircleQueue::at(int i)
{
	return array[i];
}