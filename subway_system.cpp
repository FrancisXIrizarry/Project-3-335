
#include "subway_system.h"

void subwaySystem::newSubWaySystem() {

  } //End of Func
double subwaySystem::haversine(double lat1, double lon1, double lat2, double lon2) {
  lat1 = TO_RAD * lat1;
  lat2 = TO_RAD * lat2;
  lon1 = TO_RAD * lon1;
  lon2 = TO_RAD * lon2;
  double dLat = (lat2 - lat1) / 2;
  double dLon = (lon2 - lon1) / 2;
  double a = sin(dLat);
  double b = sin(dLon);
  return 2 * R * asin(sqrt(a * a + cos(lat1) * cos(lat2) * b * b));
}
