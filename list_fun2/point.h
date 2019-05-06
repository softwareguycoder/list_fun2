/*
 * point.h
 *
 *  Created on: May 2, 2019
 *      Author: bhart
 */

#ifndef __POINT_H__
#define __POINT_H__

typedef struct _tagPOINT {
  int x;
  int y;
} POINT, *LPPOINT, **LPPPOINT;

LPPOINT CreatePoint(int x, int y);
void DestroyPoint(void* pvPoint);
BOOL PointEquals(void* pvPoint1, void* pvPoint2);
void PrintPoint(LPPOINT lpPoint);

#endif /* __POINT_H__ */
