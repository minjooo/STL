#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <chrono>

void save(std::string fname)
{
	//fname을 읽기모드로 연다
	std::ifstream in(fname);
	if (!in) {
		std::cout << "뭔가가 잘못됨" << std::endl;
	}

	//하드디스크에 저장할 파일을 덧붙여 쓰기
	std::ofstream out("2019 STL 화56 금23 강의저장.txt", std::ios::app);

	//읽은 모든 내용을 쓰기파일에 쓴다
	//copy(어디부터, 어디까지, 어디로);
	copy(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(out));

	//저장한 시간도 기록한다
	//1970이후의 틱수를 얻어온다
	auto tick = std::chrono::system_clock::now();
	//time형식으로 변환한다
	auto time = std::chrono::system_clock::to_time_t(tick);
	//글자로 바꾼다
	std::string date(ctime(&time));

	out << std::endl;
	out << "=========================" << std::endl;
	out << " " << date;
	out << "=========================" << std::endl;
	out << std::endl << std::endl;
}