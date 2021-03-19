//
//  main.cpp
//  Lesson21
//
//  Created by admin on 19.03.2021.
//

#include <iostream>
#include <string>



class Doors
{
public:
    Doors(int d = 4) : doors_number(d)
    {
        std::cout << "Construct_0: Doors" << std::endl;
    }
    
    
    ~Doors()
    {
        std::cout << "Doors class deleted" << std::endl;
    }
    
private:
    int doors_number = 4;
};

class Engine
{
public:
    
    Engine(std::string m="V-8") : model(m)
    {
        std::cout << "Construct_0: Engine" << std::endl;
    }

    void SetModel(std::string m)
    {
        model = m;
        
    }
    
    ~Engine()
    {
        std::cout << "Engine class deleted" << std::endl;
    }
    
private:
    std::string model;
    
};


class Car: public Engine, public Doors
{
public:
    Car() : Engine()
    {
        ++activation_count;
        std::cout << "Construct_0: Car" << std::endl;
    }
    
    Car(int d, int w) : num_doors(d), num_wheels(w)
    {
        ++activation_count;
        std::cout << "Construct_1: Car" << std::endl;
    }
    
    
    Car(const Car& car)
    {
        ++activation_count;
        std::cout << "Copy_Construct:Car" << std::endl;
    }
    
    int num_doors;
    int num_wheels;
    
    static int activation_count;
    
    ~Car()
    {
        --activation_count;
        std::cout << "Car class deleted. activation_count: " << activation_count
                  << std::endl;
    }
    
private:
    std::string m_model;
    std::string m_number;
    
};

class BMW : public Car
{
public:
    BMW(std::string m)
    {
        SetModel(m);
        std::cout << "Construct_0:BMW" << std::endl;
    }
    
    ~BMW()
    {
        std::cout << "BMW class deleted" << std::endl;
    }
    
};





int Car::activation_count = 0;


Car paint_the_car(Car& car)
{
    std::cout << "paint the car function" << std::endl;
    return Car();
}


int main(int argc, const char * argv[]) {

    std::cout << "==========================================" << std::endl;
    Car simple_car;
    std::cout << "simple_car.activation_count: " << simple_car.activation_count
              << std::endl;
    std::cout << "==========================================" << std::endl;
    Car car_1(4, 4);
    
    std::cout << "car_1.activation_count: " << car_1.activation_count
              << std::endl;
    std::cout << "==========================================" << std::endl;
    
    Car old_car = paint_the_car(car_1);
    std::cout << "old_car.activation_count: " << old_car.activation_count
              << std::endl;
    std::cout << "==========================================" << std::endl;
    BMW x3("v-12");
    std::cout << "x3.activation_count: " << x3.activation_count
              << std::endl;
    return 0;
}
