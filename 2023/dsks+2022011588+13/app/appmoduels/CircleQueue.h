#include "CircleQueuenode.h" 
class CircleQueue
{
public:
	CircleQueue();    //Ĭ�ϵĶ�������Ϊ8 
	~CircleQueue();
public:
	CircleQueuenode* at(int i); //����λ�õ����� 
	void InitCircleQueue();//���г�ʼ�� 
	void CleanQueue();//��ն���  
	bool QueueHead(CircleQueuenode * elem);//ȡ��ͷ 
	bool EmptyQueue();//�ж϶����Ƿ�Ϊ��  
	bool FullQueue();//�ж϶����Ƿ�Ϊ��  
	bool EnQueue(CircleQueuenode * elem);//����� 
	bool DeQueue(CircleQueuenode * elem);//������  
	int QueueLength();//���س���  
	int getQueuefront();//����ͷָ��λ�� 
	int getQueuerear();//����βָ��λ�� 
private:
	int queuerear = 0;
	int queuefront = 0;
	CircleQueuenode* array[8];//�ײ�Ϊ���� 
};