/* 
   This file implements the methods prototyped in rect.h
*/

#include <stdio.h>
#include "rect.h"

void InitRect(struct rect *rectangle) {
  int swx, swy, nwx, nwy, nex, ney, sex, sey;
  printf("Enter the coordinates for the south-west point separated by a comma: ");
  scanf("%d,%d", &swx, &swy);
  printf("\nEnter the coordinates for the north-west point separated by a comma: ");
  scanf("%d,%d", &nwx, &nwy);
  printf("\nEnter the coordinates for the north-east point separated by a comma: ");
  scanf("%d,%d", &nex, &ney);
  printf("\nEnter the coordinates for the south-east point separated by a comma: ");
  scanf("%d,%d", &sex, &sey);
  rectangle->sw.x = swx;
  rectangle->sw.y = swy;
  rectangle->nw.x = nwx;
  rectangle->nw.y = nwy;
  rectangle->ne.x = nex;
  rectangle->ne.y = ney;
  rectangle->se.x = sex;
  rectangle->se.y = sey;
}

int ValidateRect(struct rect rectangle) {
  int true = 0;
  if (rectangle.sw.x < rectangle.se.x) {
    true++;
  } 
  if (rectangle.sw.y < rectangle.nw.y) {
    true++;
  }
  if (rectangle.nw.x < rectangle.ne.x) {
    true++;
  }
  if (rectangle.se.y < rectangle.ne.y) {
    true++;
  }
  if (rectangle.sw.y == rectangle.se.y) {
    true++;
  }
  if (rectangle.nw.y == rectangle.ne.y) {
    true++;
  }
  if (rectangle.sw.x == rectangle.nw.x) {
    true++;
  }
  if (rectangle.se.x == rectangle.ne.x) {
    true++;
  }
  if (true == 8) {
    return 1;
  } else {
    return 0;
  }
}

int RectArea(struct rect rectangle) {
  int base, height, area;
  base = rectangle.se.x - rectangle.sw.x;
  height = rectangle.nw.y - rectangle.sw.y;
  area = base*height;
  return area;
}

void RotateRect(struct rect *rectangle) {
  printf("Rotating Rectangle...");
  struct point temp;
  rectangle->nw = rectangle->sw;
  rectangle->sw = rectangle->se;
  rectangle->se = rectangle->ne;
  rectangle->ne = temp;
}

void PrintRect(struct rect rectangle) {
  printf("\nSouth West Coordinates: (%d, %d)\n", rectangle.sw.x, rectangle.sw.y);
  printf("North West Coordinates: (%d, %d)\n", rectangle.nw.y, rectangle.nw.y);
  printf("North East Coordinates: (%d, %d)\n", rectangle.ne.x, rectangle.ne.y);
  printf("South East Coordinates: (%d, %d)\n", rectangle.se.x, rectangle.se.y);
}


