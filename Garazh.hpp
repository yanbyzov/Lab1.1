#pragma once
#include <string>
#include <iostream>

class Garazh{
protected:
  std::string brand;//марка
  std::string model;//модель
  int v;//объ€м двигател€
  void read(std::istream& in);//считывание
  void write(std::ostream& out) const;//вывод
public:
  Garazh(const std::string& brand = "", const std::string& model = "", int v = 0);
  Garazh(const Garazh& g);
  virtual ~Garazh();
  /*геттеры сеттеры*/
  std::string& Brand();
  std::string Model();
  int& V();
};