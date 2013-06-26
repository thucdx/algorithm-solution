#include <iostream>
using namespace std;


int polySides; //how many corners the polygon has
float polyX[]; //horizonal cooridnates of corners
float polyY[]; //vertical coordiantes of corners.
float x,y ;// point to be tested
bool pointInPolygon() {

  int      i, j=polySides-1 ;
  boolean  oddNodes=NO      ;

  for (i=0; i<polySides; i++) {
    if (polyY[i]<y && polyY[j]>=y
    ||  polyY[j]<y && polyY[i]>=y) {
      if (polyX[i]+(y-polyY[i])/(polyY[j]-polyY[i])*(polyX[j]-polyX[i])<x) {
        oddNodes=!oddNodes; }}
    j=i; }

  return oddNodes; }
