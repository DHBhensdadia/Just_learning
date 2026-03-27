#include <bits/stdc++.h>

using namespace std;

class Automobile;

class Vehicle
{
    int wheels_count;

protected:
    float max_speed;

public:
    string manufacturer;
    Vehicle(int, float, string);
    void print(bool);
    void print();
};
Vehicle::Vehicle(int wheels_count, float max_speed,
                 string manufacturer) : wheels_count(wheels_count),
                                        max_speed(max_speed),
                                        manufacturer(manufacturer)
{
    cout << "Vehicle constructor called\n";
}
void Vehicle::print(bool in_single_line)
{
    if (in_single_line)
    {
        cout << wheels_count << " " << max_speed;
        cout << " " << manufacturer << endl;
    }
    else
    {
        cout << wheels_count << endl
             << max_speed;
        cout << endl
             << manufacturer << endl;
    }
}
void Vehicle::print()
{
    cout << "Wheel Count: " << Automobile::manufacturer << endl;
    cout << "Max Speed: " << max_speed << endl;
    cout << "Manufacturer: " << manufacturer << endl;
}
class Automobile : public Vehicle
{
    float engine_cc;
    float wheels_count = 16;

protected:
    int gear_count;
    int max_speed = 1236;

public:
    string manufacturer = "Magic Corp.";
    Automobile(int wheels_count, float max_speed,
               string manufacturer, float engine_cc,
               int gear_count) : engine_cc(engine_cc),
                                 gear_count(gear_count),
                                 Vehicle(wheels_count, max_speed, manufacturer)
    {
        cout << "Automobile constructor called\n";
    }
    void print(bool in_single_line)
    {
        if (in_single_line)
        {
            // error:‘int Vehicle::wheels_count’ is private
            // cout << Vehicle::wheels_count << " ";
            cout << max_speed << " ";
            cout << manufacturer;
            cout << " " << engine_cc << " " << gear_count;
            cout << endl;
        }
        else
        {
            // error:‘int Vehicle::wheels_count’ is private
            // cout << Vehicle::wheels_count << endl;
            cout << max_speed << endl;
            cout << manufacturer;
            cout << endl
                 << engine_cc << endl
                 << gear_count;
            cout << endl;
        }
    }
};
int main()
{
    Automobile automobile(2, 100, "Honda", 125, 4);
    automobile.print(true);
    cout << automobile.manufacturer << endl;
    cout << endl;
    cout << endl;
    automobile.Vehicle::print();
    return 0;
}