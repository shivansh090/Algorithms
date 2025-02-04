#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Fruit{
public:
    string name;
    string color;
    Fruit(string name, string color) {
        this->name = name;
        this->color = color;
        cout << "Constructor called" << endl;
    }
};

class Encapsulation{
    int x = 1;
public:
    void getx() {
        cout << x << endl;
    }
    void setx(int x) {
        this->x = x;
    }
};

class Parent1 {
public:
    int x = 1;
    Parent1() {
        cout << "Parent1" << endl;
    }
};

class Parent2 {
public:
    int y = 2;
    Parent2() {
        cout << "Parent2" << endl;
    }
};

class Child : public Parent1, public Parent2 {
public:
    Child() {
        cout << "Child" << endl;
    }
};

class complex {
public:
    int real;
    int img;

    complex(int x, int y) {
        real = x;
        img = y;
    }
    complex operator+(const complex &x) {  // Changed to accept const reference
        complex ans(0, 0);
        ans.real = this->real + x.real;
        ans.img = this->img + x.img;
        return ans;
    }
};

int main() {
    // Fruit f("Apple", "red");
    // cout << f.name;
    
    // Encapsulation e;
    // e.getx();
    // e.setx(5);
    // e.getx();
    
    // Child c;
    // cout << c.x;
    
    complex c(1, 2);
    complex d(2, 2);
    complex a = c + d;  // This line now works properly
    cout << a.real << "+" << a.img << "i" << endl;
    return 0;
}
