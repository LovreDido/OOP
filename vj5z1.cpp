#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>


struct karta {
	char boja;   
	int broj;   


	karta(int broj, char boja) : broj(broj), boja(boja) {}
};


struct igrac {
	std::string ime;
	std::vector<karta> ruka;  
	int bodovi;               


	igrac(std::string ime) : ime(ime), bodovi(0) {}

	
	void dodaj_karte(const std::vector<karta>& karte) {
		ruka = karte;
	}

	
	void akuza() {
	
		for (char boja : {'H', 'D', 'C', 'S'}) {
			int napola = 0;
			for (const karta& k : ruka) {
				if (k.boja == boja && (k.broj == 1 || k.broj == 2 || k.broj == 3)) {
					napola++;
				}
			}
			if (napola == 3) {
				bodovi += 3;
			}
		}

	
		for (int broj = 1; broj <= 3; ++broj) {
			int isti = std::count_if(ruka.begin(), ruka.end(), [broj](const karta& k) { return k.broj == broj; });
			if (isti >= 3) {
				bodovi += (isti == 3) ? 3 : 4;
			}
		}
	}

	void ispisi() const {
		std::cout << ime << " - Bodovi: " << bodovi << std::endl;
	}
};


struct Mac {
	std::vector<karta> karte;
	std::vector<char> boje = { 'H', 'D', 'C', 'S' };  


	Mac() {
		for (char boja : boje) {
			for (int broj = 1; broj <= 10; ++broj) {
				karte.push_back(karta(broj, boja));
			}
		}
	}

	
	void mjesanje() {
		srand(time(0));
		std::random_shuffle(karte.begin(), karte.end());
	}

	
	std::vector<std::vector<karta>> podijeli(int brojIgraca) {
		std::vector<std::vector<karta>> ruke(brojIgraca);
		int kartePoIgracu = karte.size() / brojIgraca;

		for (int i = 0; i < brojIgraca; ++i) {
			for (int j = 0; j < kartePoIgracu; ++j) {
				ruke[i].push_back(karte[i * kartePoIgracu + j]);
			}
		}

		return ruke;
	}
};

int main() {
	int brojIgraca;

	
	std::cout << "Unesite broj igrača (2 ili 4): ";
	std::cin >> brojIgraca;

	if (brojIgraca != 2 && brojIgraca != 4) {
		std::cout << "Podržani su samo 2 ili 4 igrača." << std::endl;
		return 1;
	}

	std::vector<igrac> igraci;


	for (int i = 0; i < brojIgraca; ++i) {
		std::string ime;
		std::cout << "Unesite ime za igrača " << i + 1 << ": ";
		std::cin >> ime;
		igraci.push_back(igrac(ime));
	}

	Mac mac;
	mac.mjesanje();


	std::vector<std::vector<karta>> ruke = mac.podijeli(brojIgraca);
	for (int i = 0; i < brojIgraca; ++i) {
		igraci[i].dodaj_karte(ruke[i]);
	}

	
	for (igrac& i : igraci) {
		i.akuza();
	}


	std::cout << "\nRezultati:\n";
	for (const igrac& i : igraci) {
		i.ispisi();
	}

	return 0;
}