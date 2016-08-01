#include <iostream>
#include <Windows.h>

typedef unsigned int uint32;
typedef unsigned char byte;
typedef char cell;

class GroundMap{

public :

	GroundMap(uint32 crow , uint32 ccol , const char* map):cc(_cc),cr(_cr){
		_cc = ccol;
		_cr = crow;
		char* d = (char*)malloc(_cr*_cc);
		memcpy( d, map , _cr*_cc);
		_map[0] = d;
		for( int n = 0 ; n < _cr ; n++){
			_map[n] = d+n*_cc;
		}
	}

	~GroundMap(){if( 0 != _map) free(*_map);}

protected:

public:

	typedef char* Row;

	typedef char* Col;

public:

	inline char& cell(uint32 index){return _map[index/_cc][index%_cc];}

	inline Row row(uint32 ri);

	inline Col col(uint32 ci);

	inline Row operator[](uint32 cr){return _map[cr];}

	inline char operator()(uint32 ri , uint32 rc){return _map[ri][rc];}

	inline operator const char*(){return &_map[0][0];}

	inline operator const char**(){return &_map[0];}

	inline uint32 size(){return _cr*_cc;}
	
private:

	uint32 _cr;

	uint32 _cc;

	char** _map;

public:

	const uint32& cr;

	const uint32& cc;

};

typedef struct _task{
	GroundMap * map;
	uint32 sx;
	uint32 sy;
	std::string path;
}task;


uint32 GenerateTask(task* t , char forward){
	uint32 numChildTask = 0;

	return numChildTask;
}

task st;

uint32 cc , cr;
GroundMap* origin;

const char* originmap;

int argument_parse(int argc , char** argv){
	for( int n = 1 ; n < argc ; n++){
		if( 0 == strcmp("-c",argv[n])){cc = atoi(argv[n++]);n++;continue;}
		if( 0 == strcmp("-r",argv[n])){cr = atoi(argv[n++]);n++;continue;}
		if( 0 == strcmp("-m",argv[n])){originmap = argv[n++];n++;continue;}
	}
	return 0;
}
int main(int argc , char** argv){
	argument_parse(argc , argv);
	GroundMap map(cr,cc,originmap);

	return 0;
}

