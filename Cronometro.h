#pragma once
#include <string>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

class Tiempo {
private:
	int min, seg;
	long long initTime;
	std::string ftime = "";
public:
	Tiempo(long long segundos) {
		initTime = segundos;
		min = int(segundos / 60);
		seg = segundos % 60;
		ftime = std::to_string(min) + ":" + std::to_string(seg);
	}
	operator std::string& () { return ftime; }
};

class Cronometro {
private:
	std::chrono::steady_clock::time_point now;
	long long tiempo = 0;
public:
	Cronometro() = default;
	void init() { now = Clock::now(); }
	void fin(){
		auto timeFin = Clock::now();
		tiempo = std::chrono::duration_cast<std::chrono::seconds>(timeFin - now).count();
	}
	long long getTiempo() { return tiempo; }
	std::string getParseTime() { return Tiempo(tiempo); }
	~Cronometro() = default;
};