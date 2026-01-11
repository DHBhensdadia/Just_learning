#include <iostream>

class class_name {
    private:                           // acsesible only inside class not outside
        // Data Members
        // Member Functions
    public:
        // Data Members
        // Member Functions
};                                     // by defoult all private


class velocity_vector 
{
    private :
        int x_axis;
        int y_axis;
        int z_axis;

    public :
        void put_comp(int x, int y, int z);
        void display_comp(){
            std::cout << x_axis << '\n';
            std::cout << y_axis << '\n';
            std::cout << z_axis << '\n';
        }
};

void velocity_vector::put_comp(int x, int y, int z)
{
    x_axis = x;
    y_axis = y;
    z_axis = z;
}


int main()
{
    velocity_vector O1;
    O1.put_comp(12, 23, 34);
    O1.display_comp;

    return 0;
}