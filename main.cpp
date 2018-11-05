#include "List.hpp"
#include "Bus.hpp"
#include "Car.hpp"
#include <fstream>
#include <iomanip>

using namespace std;


int main(){
   setlocale(LC_ALL, "");
   List<Car> cars;
   List<Bus> bus;
   Car ct;
   Bus bt;
   ifstream in;
   ofstream out;
   int ch1, ch2, n;
   while(true){
		cout << "\n\n1. Добавить\n2. Удалить\n3. Изменить\n4. Сохранить\n5. Загрузить\n6. Вывести\n7. Выход\n";
		while(!(cin >> ch1) && ch1 > 0 && ch1 < 7);
		if(ch1 == 7) return 0;
		cout << "1. Машина\n2. Автобус\n";
		while(!(cin >> ch2) && ch2 > 0 && ch2 < 4);
		switch(ch1){
		case 1:

			   switch(ch2){
			   case 1:
				   cout << "Марка модель объём цвет тип_КПП\n";
				   cin >> ct;
				   cars.add(ct);
				   break;
			   case 2:
				   cout << "Марка модель объём пункт_назначени сидячие всего_мест\n";
				   cin >> bt;
				   bus.add(bt);
				   break;
			   }
			
			break;
		case 2:
			cout << "Индекс\n";
			switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < cars.size());
				   cars.remove(ch1);
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bus.size());
				   bus.remove(ch1);
				   break;
			   }
			break;
		case 3:
			   cout << "Индекс\n";
			   switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < cars.size());
				   cout << "Марка модель объём цвет тип_КПП\n";
				   cin >> cars[ch1];
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bus.size());
				   cout << "Марка модель объём пункт_назначени сидячие всего_мест\n";
				   cin >> bus[ch1];
				   break;
			   }
			break;
		case 4:
			switch(ch2){
			   case 1:
				   out.open("cars");
				   out << cars.size() << '\n';
				   for(int i = 0; i < cars.size(); ++i)
						out << cars[i] << '\n';
				   break;
			   case 2:
				   out.open("bus");
				   out << bus.size() << '\n';
				   for(int i = 0; i < bus.size(); ++i)
						out << bus[i] << '\n';
				   break;
			   }
			out.close();
			break;
		case 5:
			   switch(ch2){
			   case 1:
				   in.open("cars");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> ct;
					   cars.add(ct);
				   }
				   break;
			   case 2:
				   in.open("bus");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> bt;
					   bus.add(bt);
				   }
				   break;
			   }
			
			in.close();
			break;
		case 6:
			cout << setw(2) << "№" << setw(10) << "Марка" << setw(10) << "Модель" << setw(10) << "Объём";
			switch(ch2){
			   case 1:
				   cout<< setw(10) << "Цвет" << setw(12) << "тип_КПП";		   
				   for(int i = 0; i < cars.size(); ++i)
						cout << '\n' << setw(2) << i 
						<< setw(10)  << cars[i].Brand()
						<< setw(10)  << cars[i].Model()
						<< setw(10)  << cars[i].V()
						<< setw(10)  << cars[i].Color()
						<< setw(12)  << cars[i].Type();
				   break;
			   case 2:
				   cout<< setw(10) << "Пункт" << setw(10) << "Сидячих" << setw(9) << "Всего";
				   for(int i = 0; i < bus.size(); ++i)
						cout << '\n' << setw(2) << i 
						<< setw(10)  << bus[i].Brand()
						<< setw(10)  << bus[i].Model()
						<< setw(10)  << bus[i].V()
						<< setw(10)  << bus[i].Place()
						<< setw(12)  << bus[i].CntSeet()
						<< setw(12)  << bus[i].Cnt();
				   break;
			   }
			break;
		}
   }
}

