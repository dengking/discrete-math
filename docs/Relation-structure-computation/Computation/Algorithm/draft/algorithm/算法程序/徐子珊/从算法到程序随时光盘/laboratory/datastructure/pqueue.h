/* 
 * File:   pqueue.h
 * Author: 徐子珊
 *
 * Created on 2009年7月1日, 下午5:07
 */

#ifndef _PQUEUE_H
#define	_PQUEUE_H

#ifdef	__cplusplus
extern "C" {
#endif
	typedef struct {
		void *heap;
		int eleSize;
		int length;
		int heapSize;
		int(*compare)(void const *,void const *);
	}PQueue;
	PQueue *initPQueue(int size,int n,int(*comp)(void const *,void const *));
	void pQueueClr(PQueue *q);
	int empty(PQueue *q);
	void enQueue(PQueue *q,void *e);
	void *top(PQueue *q);
	void * deQueue(PQueue *q);
	void fix(PQueue *q);
#ifdef	__cplusplus
}
#endif

#endif	/* _PQUEUE_H */

