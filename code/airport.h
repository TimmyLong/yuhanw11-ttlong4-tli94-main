#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Airport {
public:
    Airport() {}
    Airport(int aid, string name, string city,
            string country,
            string iata, string icao,
            double latitude, double longitude, int altitude, string timezone) {
        this->id = aid;
        this->name = name;
        this->city = city;
        this->country = country;
        this->iata = iata;
        this->icao = icao;
        this->latitude = latitude;
        this->longitude = longitude;
        this->altitude = altitude;
        this->timezone = timezone;
    }

    void display() {
        cout << "Airport information" << endl;
        cout << "Airport  :" << id << endl;
        cout << "Name     :" << name << endl;
        cout << "City     :" << city << endl;
        cout << "Country  :" << country << endl;
        cout << "IATA     :" << iata << endl;
        cout << "ICAO     :" << icao << endl;
        cout << "Latitude :" << latitude << endl;
        cout << "Longitude:" << longitude << endl;
        cout << "Altitude :" << altitude << endl;
        cout << "Timezone :" << timezone << endl;
    }

    int id;
    string name;
    string city;
    string country;
    string iata;
    string icao;
    double latitude;
    double longitude;
    int altitude;
    string timezone;

};


class Airline{
public:
    Airline() {}
    Airline(string airline,
            int airline_id,
            string src,
            int src_id,
            string dst,
            int dst_id){
        this->airline = airline;
        this->airline_id = airline_id;
        this->src = src;
        this->src_id = src_id;
        this->dst = dst;
        this->dst_id = dst_id;
    }
    void display() {
        cout << "Airline information" << endl;
        cout << "Airline            :" << airline << endl;
        cout << "Airline ID         :" << airline_id << endl;
        cout << "Source airport     :" << src << endl;
        cout << "Source  ID         :" << src_id << endl;
        cout << "Destination airport:" << dst << endl;
        cout << "Destination ID     :" << dst_id << endl;
    }

    string airline;
    int airline_id;
    string src;
    int src_id;
    string dst;
    int dst_id;
};



#endif // AIRPORT_H_INCLUDED
