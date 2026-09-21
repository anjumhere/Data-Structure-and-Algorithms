#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::string;

class Teacher {
public:
  int age;
  string name;
  string classRoom;
  double salary;

  Teacher(int age, string name, string classRoom, double salary) {
    this->age = age;
    this->name = std::move(name);
    this->classRoom = std::move(classRoom);
    this->salary = salary;
  }
};
int main() {
  Teacher t1(21, "Anjum", "12-B", 51555.3);
  cout << t1.name << '\n';
  return 0;
}
