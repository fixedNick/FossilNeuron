#include "Fossil.h"

Fossil::Fossil() {}
Fossil::Fossil(string _name) {
	name = _name;
}

void Fossil::add_neuron(Neuron n)
{
	neurons.push_back(n);
}

bool Fossil::is_digged_fossil_is_equal_this_fossil(DigFossil digged_fossil)
{
	// ���� �����������, ������� ������
	auto digged_fossil_elements = digged_fossil.get_elements(); // �� ���
	int digged_fossil_elements_count = digged_fossil.get_elements_count();

	vector<int> neuron_ids_do_not_recognize;
	for(int i = 0; i < digged_fossil_elements_count; i++)
	{ 
		// ���� ����� ����� j<neurons.size() -> isElementRecognized �� ������ true, 
		// ������ ���� �� ��������� ����������� ����������� �� ��� ���������
		// ������ ������������ ��� ������ - ���������� false, ��� �� ���� ����������, ������� �� ����
		bool isElementRecognized = false; 
		for (int j = 0; j < neurons.size(); j++)
		{
			bool is_neuron_to_skip = false;
			for (auto& neuron_id : neuron_ids_do_not_recognize) // ���� ����������
			{
				if (neuron_id == j)
				{
					is_neuron_to_skip = true;
					break; // ������ �� ����� ����������
				}
			}

			if (is_neuron_to_skip) continue;

			isElementRecognized = neurons[j].recognize(digged_fossil_elements[i]);
			if (isElementRecognized == true) // ���������� �������, ��������� � ���������� �������������
			{
				neuron_ids_do_not_recognize.push_back(j);
				break; // �������� ����� ��� �������������
			}
		}
		// ��� ������������� ���������� �������� ���� �� ��������� ��� �������(�� ���� �� ���������� ��� ��������)
		// ������ �� ���������� ��������� ������� �������(��� � ��� ����������) - �� ������ �� ����� � ����� ������ TRUE
		// ���� �������� ����� - �� isElementRecognized ������ TRUE
		// � ������ �� �������� � ��������� ��������
		if (isElementRecognized == false) 
			return false;
	}
	return true;
}
