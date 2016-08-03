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
		_map = (char*)malloc(sizeof(char)*_cc*_cr);
		memcpy(_map,map,_cc*_cr);
	}

	GroundMap(const GroundMap& gm):cc(_cc),cr(_cr){
		_cc = gm._cc;
		_cr = gm._cr;
		_map = (char*)malloc(sizeof(char)*_cc*_cr);
		memcpy(_map,gm._map,_cc*_cr);
	}

	~GroundMap(){if( 0 != _map) free(_map);}

public:

	GroundMap& operator=(const GroundMap& gm){
		_cc = gm._cc;
		_cr = gm._cr;
		_map = (char*)malloc(sizeof(char)*_cc*_cr);
		memcpy(_map,gm._map,_cc*_cr);
		return *this;
	}

protected:

public:

	typedef char* Row;

	typedef char* Col;

public:

	inline char& cell(uint32 index){return _map[index];}

	inline char& cell(uint32 ri , uint32 ci){return _map[_cc*ri+ci];}

	inline Row row(uint32 ri){return &_map[ri*_cc];}

	inline Col col(uint32 ci){return &_map[ci];}

	inline Row operator[](uint32 ri){return &_map[ri*_cc];}

	inline char& operator()(uint32 ri , uint32 ci){return _map[_cc*ri+ci];}

	inline operator const char*(){return &_map[0];}

	inline uint32 size() const {return _cr*_cc;}
	
private:

	uint32 _cr;

	uint32 _cc;

	char* _map;

public:

	const uint32& cr;

	const uint32& cc;

};

typedef struct _task{
	char forward;
	uint32 sx;
	uint32 sy;
	uint32 x;
	uint32 y;
	std::string path;
	GroundMap map;
}task;

task st;

uint32 cc , cr;
const GroundMap* origin = NULL;

const char* originmap;

int argument_parse(int argc , char** argv){
	for( int n = 1 ; n < argc ; n++){
		if( 0 == strcmp("-c",argv[n])){cc = atoi(argv[n++]);n++;continue;}
		if( 0 == strcmp("-r",argv[n])){cr = atoi(argv[n++]);n++;continue;}
		if( 0 == strcmp("-m",argv[n])){originmap = argv[n++];n++;continue;}
	}
	return 0;
}

bool validation(const GroundMap* map){
	uint32 x = 0 , y = 0;
	byte tid = 1;
	byte *team = (byte*)malloc(map->size());
	for( int n = 0 ; n < map->cc ; n++){
		for(int m = 0 ; m < map->cr ; m++){
			
		}
	}
	return false;
}

uint32 GenerateTask(task* t_old  , task (*t_new)[4]){
	if( !t_old || !t_new ) return 0;
	uint32 numChildTask = 0;
	uint32 x = t_old->x;
	uint32 y = t_old->y;
	switch( t_old->forward ){
	case 'u':while(('1'!=t_old->map(x,y--))&&(t_old->map.cell(x,y)='1'));break;
	case 'r':while(('1'!=t_old->map(x++,y))&&(t_old->map.cell(x,y)='1'));break;
	case 'd':while(('1'!=t_old->map(x,y++))&&(t_old->map.cell(x,y)='1'));break;
	case 'l':while(('1'!=t_old->map(x--,y))&&(t_old->map.cell(x,y)='1'));break;
	default:break;
	}
	if( x == t_old->x && y == t_old->y) return numChildTask;
	if(validation(&t_old->map)){
		switch( t_old->forward ){
		case 'u':t_new[0]->forward='r';t_new[1]->forward='d';t_new[2]->forward='l';break;
		case 'r':t_new[0]->forward='u';t_new[1]->forward='d';t_new[2]->forward='l';break;
		case 'd':t_new[0]->forward='u';t_new[1]->forward='r';t_new[2]->forward='l';break;
		case 'l':t_new[0]->forward='u';t_new[1]->forward='r';t_new[2]->forward='d';break;
		default:break;
		}
	}
	return numChildTask;
}

int main(int argc , char** argv){
	argument_parse(argc , argv);
	GroundMap map(cr,cc,originmap);
	origin = &map;
	
	return 0;
}

