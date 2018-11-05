#include "Car.hpp"
/*public*/
  Car::Car(const std::string& brand, const std::string& model, int v, const std::string& color, const std::string& type)
	  :Garazh(brand, model, v), color(color), type(type){}
  Car::Car(const Car& g):Garazh(g.brand, g.model, g.v), color(g.color), type(g.type){}
  Car::~Car(){}
/*геттеры сеттеры*/
  std::string& Car::Color(){
	   return color;
  }
  std::string& Car::Type(){
	   return type;
  }

std::istream& operator>>(std::istream& in, Car& g){
   g.read(in);
   in >> g.color >> g.type;
   return in;
}
std::ostream& operator<<(std::ostream& out, const Car& g){
	g.write(out);
	out << g.color << ' ' << g.type;
	return out;

}