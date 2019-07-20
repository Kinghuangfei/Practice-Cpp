#include <iostream>
#include <string>
using namespace std;

class Person {
  public:
    Person (const string& name , const string& gender , const int age)
      : _name (name)
        , _gender (gender)
        , _age (age) {
          cout << "Person:: Person" << endl;

        }

    virtual void BuyTicker () {
      cout << "adult : 全价票" << endl;

    }
  private:
    string _name;
    string _gender;
    int _age;

};

class Student : public Person {
  public:
    Student (const string& name , const string& gender , const int age , const int sno)
      : Person (name , gender , age)
        , _sno (sno) {
          cout << "Student:: Student" << endl;

        }

    virtual void BuyTicker () {
      cout << "student : 半价票" << endl;

    }
  private:
    int _sno;

};

class Soldier : public Person {
  public:
    Soldier (const string& name , const string& gender , const int age , const string& army)
      : Person (name , gender , age)
        , _Army (army) {
          cout << "Soldier:: Soldier" << endl;

        }

    virtual void BuyTicket () {
      cout << "Soldier: 免费票" << endl;

    }
  private:
    string _Army;

};

void TestFunc (Person& p) {
  p.BuyTicker ();

}

int main () {
  Person p ("Tom" , "男" , 13);
  Student stu ("July" , "女" , 13 , 1001);
  Soldier sold ("Bob" , "男" , 23 , "下士");
  sold.BuyTicker ();
  TestFunc (sold);
  TestFunc (p);
  TestFunc (stu);
  return 0;

}

