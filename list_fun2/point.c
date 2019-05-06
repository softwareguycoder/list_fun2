/*
 * point.c
 *
 *  Created on: May 2, 2019
 *      Author: bhart
 */

#include "stdafx.h"
#include "list_fun2.h"

#include "point.h"

LPPOINT CreatePoint(int x, int y) {
  LPPOINT lpResult = (LPPOINT) malloc(sizeof(POINT));
  if (lpResult == NULL) {
    return lpResult;
  }

  memset(lpResult, 0, sizeof(POINT));
  lpResult->x = x;
  lpResult->y = y;
  return lpResult;
}

void DestroyPoint(void* pvPoint) {
  if (pvPoint == NULL) {
    return;
  }

  free(pvPoint);
}

BOOL PointEquals(void* pvPoint1, void* pvPoint2) {
  if (pvPoint1 == NULL
      && pvPoint2 == NULL) {
    return TRUE;
  }

  if ((pvPoint1 == NULL &&
      pvPoint2 != NULL) ||
      (pvPoint1 != NULL &&
          pvPoint2 == NULL)) {
    return FALSE;
  }

  LPPOINT lpPoint1 = (LPPOINT)pvPoint1;
  LPPOINT lpPoint2 = (LPPOINT)pvPoint2;

  return lpPoint1->x == lpPoint2->x
      && lpPoint1->y == lpPoint2->y;
}

void PrintPoint(void* pvPoint) {
  if (pvPoint == NULL) {
    return;
  }

  printf(PRINT_POINT_FORMAT,
      ((LPPOINT)pvPoint)->x, ((LPPOINT)pvPoint)->y);
}
