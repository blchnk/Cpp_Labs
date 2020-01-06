#include <iostream>
#include "ITaxPayment.h"
#include "Magazine.h"
#include "Pharmacy.h"
#include "Boutique.h"

int main()
{
	setlocale(LC_CTYPE, "rus");

	const int len = 3;
	Magazine* magazine[len];

	magazine[0] = new Pharmacy("dr.Dre", "Independent st. 25", 2005, 1, 1000, 100, true);
	magazine[1] = new Pharmacy("dr.House", "Republic st. 10", 2001, 1, 1500, 150, true);
	magazine[2] = new Boutique("Gucci", "Republic st. 12", 2010, 2, 5000, 500, "from 8 a.m. to 6 p.m.", 8);

	for (int i = 0; i < len; i++) {
		magazine[i]->Print();
		delete magazine[i];
	}
}

//									Lab_3 Task_2(V2)
//			
//	Класс МАГАЗИН + классы АПТЕКА, БУТИК. Реализовать схему наследования классов и
//	корректно распределить по классам данные: название, адрес, год основания, номер,
//	суммарная прибыль, доход, время работы, количество клиентов со скидкой,
//	тип (круглосуточно или нет). Интерфейс налогоплательщика ITaxPayment с методом
//	void payTax(). Для бутика налог рассчитывается с учетом земельного налога, для
//	аптеки – без (коэффициенты задайте произвольно). Сумма налогов должна быть
//  вычтена из суммарной прибыли. В main() создать 2 аптеки и 1 бутик,
//	продемонстрировать полиморфизм payTax().
