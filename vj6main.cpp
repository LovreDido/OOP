#include <iostream>
#include <utility>
#include "vj6.h"

container napravi_container()
{
	container tmp(2);
	tmp.push_back(100);
	tmp.push_back(200);
	return tmp; 
}
void funkcija_po_vrijednosti(container c)
{
	std::cout << "Primljen container kopijom (size="
		<< c.size() << ")\n";
}
int main()
{
	std::cout << "1. Kreiranje i dodavanje elemenata\n";
	container c1(2);
	c1.push_back(10);
	c1.push_back(20);
	c1.push_back(30); 
	std::cout << "\n2. Kopiranje pomocu copy konstruktora\n";
	container c2 = c1;
	std::cout << "\n3. Move konstruktor (std::move)\n";
	container c3 = std::move(c1);
	std::cout << "\n4. Prosljeđivanje containera po vrijednosti\n";
	funkcija_po_vrijednosti(c2);
	std::cout << "\n5. Vraćanje containera iz funkcije\n";
	container c4 = napravi_container();
	std::cout << "\n6. Test realokacije dodavanjem elemenata\n";
	c4.push_back(300);
	c4.push_back(400);
	std::cout << "\n7. Ispis svih elemenata\n";
	for (size_t i = 0; i < c4.size(); i++)
		std::cout << "Index " << i << ": " << c4.at(i) << "\n";
	return 0;
}
