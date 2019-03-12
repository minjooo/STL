#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <chrono>

void save(std::string fname)
{
	//fname�� �б���� ����
	std::ifstream in(fname);
	if (!in) {
		std::cout << "������ �߸���" << std::endl;
	}

	//�ϵ��ũ�� ������ ������ ���ٿ� ����
	std::ofstream out("2019 STL ȭ56 ��23 ��������.txt", std::ios::app);

	//���� ��� ������ �������Ͽ� ����
	//copy(������, ������, ����);
	copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(out));

	//������ �ð��� ����Ѵ�
	//1970������ ƽ���� ���´�
	auto tick = std::chrono::system_clock::now();
	//time�������� ��ȯ�Ѵ�
	auto time = std::chrono::system_clock::to_time_t(tick);
	//���ڷ� �ٲ۴�
	std::string date(ctime(&time));

	out << std::endl;
	out << "=========================" << std::endl;
	out << " " << date;
	out << "=========================" << std::endl;
	out << std::endl << std::endl;
}