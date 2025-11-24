#include "vj6.h"

container::container(size_t initial_capacity)
	: data(nullptr), m_size(0), m_capacity(initial_capacity)
{
	if (initial_capacity > 0)
		data = new int[initial_capacity];

	std::cout << "[Konstruktor] Kreiran container s kapacitetom "
		<< m_capacity << std::endl;
}

container::container(const container& other)
	: data(nullptr), m_size(other.m_size), m_capacity(other.m_capacity)
{
	if (m_capacity > 0)
		data = new int[m_capacity];

	for (size_t i = 0; i < m_size; i++)
		data[i] = other.data[i];

	std::cout << "[Copy konstruktor] Kopiran container" << std::endl;
}

container::container(container&& other) noexcept
	: data(other.data), m_size(other.m_size), m_capacity(other.m_capacity)
{
	other.data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;

	std::cout << "[Move konstruktor] Premješten container" << std::endl;
}

container::~container()
{
	delete[] data;
	std::cout << "[Destruktor] Uništen container" << std::endl;
}

void container::push_back(int value)
{
	if (m_size >= m_capacity)
	{
		size_t new_capacity = (m_capacity == 0 ? 1 : m_capacity * 2);
		int* new_data = new int[new_capacity];

		for (size_t i = 0; i < m_size; i++)
			new_data[i] = data[i];

		delete[] data;
		data = new_data;
		m_capacity = new_capacity;

		std::cout << "[Realokacija] Novi kapacitet: " << m_capacity << std::endl;
	}

	data[m_size++] = value;
}

int& container::at(size_t index)
{
	if (index >= m_size)
		throw std::out_of_range("Indeks izvan granica");
	return data[index];
}

const int& container::at(size_t index) const
{
	if (index >= m_size)
		throw std::out_of_range("Indeks izvan granica");
	return data[index];
}
