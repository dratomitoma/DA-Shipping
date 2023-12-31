//
// Created by tiago on 27/05/2023.
//

#include "calculations.h"

using namespace std;

double convertToRadians(double coord){
    return (coord*M_PI)/180;
}

double haversineDistance(double lon1, double lat1, double lon2, double lat2){
    double radLon1 = convertToRadians(lon1), radLat1 = convertToRadians(lat1), radLon2 = convertToRadians(lon2), radLat2 = convertToRadians(lat2);

    double deltaLon = radLon2 - radLon1, deltaLat = radLat2 - radLat1;

    double aux = pow(sin(deltaLat/2),2) + cos(radLat1) * cos(radLat2) * pow(sin(deltaLon/2),2);

    double c = 2 * atan2(sqrt(aux), sqrt(1-aux));

    return 6371000 * c;
}

double long calculateMean(const vector<Node*>& cluster){
    double mean = 0.0;
    auto size = (double long)cluster.size();
    for(Node* node : cluster){
        mean += node->getDist();
    }
    return (mean / size);
}

double long calculateStandardDeviation(const vector<Node*>& cluster){

    double long variance = 0.0;

    double long mean = calculateMean(cluster);

    auto size = (double long)cluster.size();

    for(Node* node : cluster){
        variance += pow(node->getDist()-mean,2);
    }

    variance /= size;

    return sqrt(variance);
}