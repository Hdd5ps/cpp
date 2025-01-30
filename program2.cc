/*
CSC 1180 - Programming C++
Kamal Raj Timilsena
Jan 29 2025
Program 2

Determine if the latitude is in the northern hemisphere, southern hemisphere, or on the equator.
Determine if the longitude is in the eastern hemisphere, western hemisphere, or on the prime meridian.

Algorithm:
Step 1 - Take in a pair of double values from user input.
Step 2 - Examine latitude: if greater than zero; north, less than zero; south, zero; equator.
Step 3 - Examine longitude: if greater than zero; east, less than zero; west, zero; prime meridian.
Step 4 - Use either hemisphere or hemispheres, based on the data.
*/

#include <iostream>
using namespace std;

int main() {
    double latitude, longitude;

    cout << "Please enter the latitude: ";
    cin >> latitude;

    cout << "Please enter the longitude: ";
    cin >> longitude;

    string latitudeHemisphere, longitudeHemisphere;

    // Determine the hemisphere based on latitude
    if (latitude > 0) {
        latitudeHemisphere = "Northern";
    } 
    else if (latitude < 0) {
        latitudeHemisphere = "Southern";
    } 
    else {
        latitudeHemisphere = "Equator";
    }

    // Determine the hemisphere based on longitude
    if (longitude > 0) {
        longitudeHemisphere = "Eastern";
    } 
    else if (longitude < 0) {
        longitudeHemisphere = "Western";
    } 
    else {
        longitudeHemisphere = "Prime Meridian";
    }

    // Output the result
    if (latitudeHemisphere == "Equator" && longitudeHemisphere == "Prime Meridian") {
        cout << "Location: Equator, Prime Meridian" << endl;
    } 
    else if (latitudeHemisphere == "Equator") {
        cout << "Location: Equator, " << longitudeHemisphere << " Hemisphere" << endl;
    } 
    else if (longitudeHemisphere == "Prime Meridian") {
        cout << "Location: " << latitudeHemisphere << ", Prime Meridian" << endl;
    } 
    else {
        cout << "Location: " << latitudeHemisphere << ", " << longitudeHemisphere << " Hemispheres" << endl;
    }

    return 0;
}