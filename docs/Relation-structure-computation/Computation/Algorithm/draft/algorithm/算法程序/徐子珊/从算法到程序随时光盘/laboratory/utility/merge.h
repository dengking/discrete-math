/* 
 * File:   merge.h
 * Author: 徐子珊
 *
 * Created on 2009年 6月 29日, 下午 10:59
 */

#ifndef _MERGE_H
#define	_MERGE_H

#ifdef	__cplusplus
extern "C" {
#endif
	void merge(void *a, int size, int p, int q, int r,int(*comp)(void *,void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _MERGE_H */

