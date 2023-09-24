// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

//bool lessThan(Data *p1, Data *p2);
bool lessThan(Data *p1, Data *p2) {
	if ((p1->lastName) < (p2->lastName)) 
		return true;
	else if ((p1->lastName) > (p2->lastName)) 
		return false;

	if ((p1->firstName) < (p2->firstName)) 
		return true;
	else if ((p1->firstName) > (p2->firstName)) 
		return false;

	if ((p1->ssn) < (p2->ssn)) 
		return true;
	return false;	
}

bool lessThanln(Data *p1, Data *p2) {
	if ((p1->lastName) < (p2->lastName))
		return true;
	return false;
}

bool lessThanfn(Data *p1, Data *p2) {
	if ((p1->firstName) < (p2->firstName))
		return true;
	return false;
}


bool lessThanSSN(Data *p1, Data *p2) {
	if ((p1->ssn) < (p2->ssn))
		return true;
	return false;
}

//Empty List of Arrays for last names

vector<string> ACOSTA[4000] = {0};
vector<string> ADAMS[4000] = {0};
vector<string> ADKINS[4000] = {0};
vector<string> AGUILAR[4000] = {0};
vector<string> AGUIRRE[4000] = {0};
vector<string> ALEXANDER[4000] = {0};
vector<string> ALLEN[4000] = {0};
vector<string> ALVARADO[4000] = {0};
vector<string> ALVAREZ[4000] = {0};
vector<string> ANDERSON[4000] = {0};
vector<string> ANDREWS[4000] = {0};
vector<string> ARMSTRONG[4000] = {0};
vector<string> ARNOLD[4000] = {0};
vector<string> AUSTIN[4000] = {0};
vector<string> AVILA[4000] = {0};
vector<string> AYALA[4000] = {0};
vector<string> BAILEY[4000] = {0};
vector<string> BAKER[4000] = {0};
vector<string> BALDWIN[4000] = {0};
vector<string> BANKS[4000] = {0};
vector<string> BARBER[4000] = {0};
vector<string> BARKER[4000] = {0};
vector<string> BARNES[4000] = {0};
vector<string> BARNETT[4000] = {0};
vector<string> BARRETT[4000] = {0};
vector<string> BARTON[4000] = {0};
vector<string> BATES[4000] = {0};
vector<string> BECK[4000] = {0};
vector<string> BECKER[4000] = {0};
vector<string> BELL[4000] = {0};
vector<string> BENNETT[4000] = {0};
vector<string> BENSON[4000] = {0};
vector<string> BERRY[4000] = {0};
vector<string> BISHOP[4000] = {0};
vector<string> BLACK[4000] = {0};
vector<string> BLAIR[4000] = {0};
vector<string> BLAKE[4000] = {0};
vector<string> BOWEN[4000] = {0};
vector<string> BOWMAN[4000] = {0};
vector<string> BOYD[4000] = {0};
vector<string> BRADLEY[4000] = {0};
vector<string> BRADY[4000] = {0};
vector<string> BREWER[4000] = {0};
vector<string> BROOKS[4000] = {0};
vector<string> BROWN[4000] = {0};
vector<string> BRYANT[4000] = {0};
vector<string> BURGESS[4000] = {0};
vector<string> BURKE[4000] = {0};
vector<string> BURNS[4000] = {0};
vector<string> BURTON[4000] = {0};
vector<string> BUSH[4000] = {0};
vector<string> BUTLER[4000] = {0};
vector<string> BYRD[4000] = {0};
vector<string> CABRERA[4000] = {0};
vector<string> CALDERON[4000] = {0};
vector<string> CALDWELL[4000] = {0};
vector<string> CAMACHO[4000] = {0};
vector<string> CAMPBELL[4000] = {0};
vector<string> CAMPOS[4000] = {0};
vector<string> CANNON[4000] = {0};
vector<string> CARDENAS[4000] = {0};
vector<string> CARLSON[4000] = {0};
vector<string> CARPENTER[4000] = {0};
vector<string> CARR[4000] = {0};
vector<string> CARRILLO[4000] = {0};
vector<string> CARROLL[4000] = {0};
vector<string> CARTER[4000] = {0};
vector<string> CASTANEDA[4000] = {0};
vector<string> CASTILLO[4000] = {0};
vector<string> CASTRO[4000] = {0};
vector<string> CERVANTES[4000] = {0};
vector<string> CHAMBERS[4000] = {0};
vector<string> CHAN[4000] = {0};
vector<string> CHANDLER[4000] = {0};
vector<string> CHANG[4000] = {0};
vector<string> CHAPMAN[4000] = {0};
vector<string> CHAVEZ[4000] = {0};
vector<string> CHEN[4000] = {0};
vector<string> CHRISTENSEN[4000] = {0};
vector<string> CLARK[4000] = {0};
vector<string> CLARKE[4000] = {0};
vector<string> COHEN[4000] = {0};
vector<string> COLE[4000] = {0};
vector<string> COLEMAN[4000] = {0};
vector<string> COLLINS[4000] = {0};
vector<string> COLON[4000] = {0};
vector<string> CONTRERAS[4000] = {0};
vector<string> COOK[4000] = {0};
vector<string> COOPER[4000] = {0};
vector<string> CORTEZ[4000] = {0};
vector<string> COX[4000] = {0};
vector<string> CRAIG[4000] = {0};
vector<string> CRAWFORD[4000] = {0};
vector<string> CROSS[4000] = {0};
vector<string> CRUZ[4000] = {0};
vector<string> CUMMINGS[4000] = {0};
vector<string> CUNNINGHAM[4000] = {0};
vector<string> CURRY[4000] = {0};
vector<string> CURTIS[4000] = {0};
vector<string> DANIEL[4000] = {0};
vector<string> DANIELS[4000] = {0};
vector<string> DAVIDSON[4000] = {0};
vector<string> DAVIS[4000] = {0};
vector<string> DAWSON[4000] = {0};
vector<string> DAY[4000] = {0};
vector<string> DEAN[4000] = {0};
vector<string> DELACRUZ[4000] = {0};
vector<string> DELEON[4000] = {0};
vector<string> DELGADO[4000] = {0};
vector<string> DENNIS[4000] = {0};
vector<string> DIAZ[4000] = {0};
vector<string> DIXON[4000] = {0};
vector<string> DOMINGUEZ[4000] = {0};
vector<string> DOUGLAS[4000] = {0};
vector<string> DOYLE[4000] = {0};
vector<string> DUNCAN[4000] = {0};
vector<string> DUNN[4000] = {0};
vector<string> DURAN[4000] = {0};
vector<string> EDWARDS[4000] = {0};
vector<string> ELLIOTT[4000] = {0};
vector<string> ELLIS[4000] = {0};
vector<string> ERICKSON[4000] = {0};
vector<string> ESPINOZA[4000] = {0};
vector<string> ESTRADA[4000] = {0};
vector<string> EVANS[4000] = {0};
vector<string> FARMER[4000] = {0};
vector<string> FERGUSON[4000] = {0};
vector<string> FERNANDEZ[4000] = {0};
vector<string> FIELDS[4000] = {0};
vector<string> FIGUEROA[4000] = {0};
vector<string> FISCHER[4000] = {0};
vector<string> FISHER[4000] = {0};
vector<string> FITZGERALD[4000] = {0};
vector<string> FLEMING[4000] = {0};
vector<string> FLETCHER[4000] = {0};
vector<string> FLORES[4000] = {0};
vector<string> FORD[4000] = {0};
vector<string> FOSTER[4000] = {0};
vector<string> FOWLER[4000] = {0};
vector<string> FOX[4000] = {0};
vector<string> FRANCIS[4000] = {0};
vector<string> FRANCO[4000] = {0};
vector<string> FRANK[4000] = {0};
vector<string> FRANKLIN[4000] = {0};
vector<string> FRAZIER[4000] = {0};
vector<string> FREEMAN[4000] = {0};
vector<string> FUENTES[4000] = {0};
vector<string> FULLER[4000] = {0};
vector<string> GALLAGHER[4000] = {0};
vector<string> GALLEGOS[4000] = {0};
vector<string> GARCIA[4000] = {0};
vector<string> GARDNER[4000] = {0};
vector<string> GARNER[4000] = {0};
vector<string> GARRETT[4000] = {0};
vector<string> GARZA[4000] = {0};
vector<string> GEORGE[4000] = {0};
vector<string> GIBSON[4000] = {0};
vector<string> GILBERT[4000] = {0};
vector<string> GILL[4000] = {0};
vector<string> GOMEZ[4000] = {0};
vector<string> GONZALES[4000] = {0};
vector<string> GONZALEZ[4000] = {0};
vector<string> GOODMAN[4000] = {0};
vector<string> GOODWIN[4000] = {0};
vector<string> GORDON[4000] = {0};
vector<string> GRAHAM[4000] = {0};
vector<string> GRANT[4000] = {0};
vector<string> GRAVES[4000] = {0};
vector<string> GRAY[4000] = {0};
vector<string> GREEN[4000] = {0};
vector<string> GREENE[4000] = {0};
vector<string> GREGORY[4000] = {0};
vector<string> GRIFFIN[4000] = {0};
vector<string> GRIFFITH[4000] = {0};
vector<string> GROSS[4000] = {0};
vector<string> GUERRA[4000] = {0};
vector<string> GUERRERO[4000] = {0};
vector<string> GUTIERREZ[4000] = {0};
vector<string> GUZMAN[4000] = {0};
vector<string> HAIL[4000] = {0};
vector<string> HALE[4000] = {0};
vector<string> HALL[4000] = {0};
vector<string> HAMILTON[4000] = {0};
vector<string> HAMMOND[4000] = {0};
vector<string> HAMPTON[4000] = {0};
vector<string> HANSEN[4000] = {0};
vector<string> HANSON[4000] = {0};
vector<string> HARDY[4000] = {0};
vector<string> HARMON[4000] = {0};
vector<string> HARPER[4000] = {0};
vector<string> HARRINGTON[4000] = {0};
vector<string> HARRIS[4000] = {0};
vector<string> HARRISON[4000] = {0};
vector<string> HART[4000] = {0};
vector<string> HARVEY[4000] = {0};
vector<string> HAWKINS[4000] = {0};
vector<string> HAYES[4000] = {0};
vector<string> HAYNES[4000] = {0};
vector<string> HENDERSON[4000] = {0};
vector<string> HENRY[4000] = {0};
vector<string> HERNANDEZ[4000] = {0};
vector<string> HERRERA[4000] = {0};
vector<string> HICKS[4000] = {0};
vector<string> HIGGINS[4000] = {0};
vector<string> HILL[4000] = {0};
vector<string> HINES[4000] = {0};
vector<string> HODGES[4000] = {0};
vector<string> HOFFMAN[4000] = {0};
vector<string> HOLLAND[4000] = {0};
vector<string> HOLMES[4000] = {0};
vector<string> HOLT[4000] = {0};
vector<string> HOPKINS[4000] = {0};
vector<string> HORTON[4000] = {0};
vector<string> HOWARD[4000] = {0};
vector<string> HOWELL[4000] = {0};
vector<string> HUANG[4000] = {0};
vector<string> HUBBARD[4000] = {0};
vector<string> HUDSON[4000] = {0};
vector<string> HUGHES[4000] = {0};
vector<string> HUNT[4000] = {0};
vector<string> HUNTER[4000] = {0};
vector<string> INGRAM[4000] = {0};
vector<string> JACKSON[4000] = {0};
vector<string> JACOBS[4000] = {0};
vector<string> JAMES[4000] = {0};
vector<string> JENKINS[4000] = {0};
vector<string> JENNINGS[4000] = {0};
vector<string> JENSEN[4000] = {0};
vector<string> JIMENEZ[4000] = {0};
vector<string> JOHNSON[4000] = {0};
vector<string> JOHNSTON[4000] = {0};
vector<string> JONES[4000] = {0};
vector<string> JORDAN[4000] = {0};
vector<string> JOSEPH[4000] = {0};
vector<string> JUAREZ[4000] = {0};
vector<string> KELLER[4000] = {0};
vector<string> KELLEY[4000] = {0};
vector<string> KELLY[4000] = {0};
vector<string> KENNEDY[4000] = {0};
vector<string> KHAN[4000] = {0};
vector<string> KIM[4000] = {0};
vector<string> KING[4000] = {0};
vector<string> KLEIN[4000] = {0};
vector<string> KNIGHT[4000] = {0};
vector<string> LAMBERT[4000] = {0};
vector<string> LANE[4000] = {0};
vector<string> LARA[4000] = {0};
vector<string> LARSON[4000] = {0};
vector<string> LAWRENCE[4000] = {0};
vector<string> LAWSON[4000] = {0};
vector<string> LE[4000] = {0};
vector<string> LEE[4000] = {0};
vector<string> LEON[4000] = {0};
vector<string> LEONARD[4000] = {0};
vector<string> LEWIS[4000] = {0};
vector<string> LI[4000] = {0};
vector<string> LIN[4000] = {0};
vector<string> LITTLE[4000] = {0};
vector<string> LIU[4000] = {0};
vector<string> LOGAN[4000] = {0};
vector<string> LONG[4000] = {0};
vector<string> LOPEZ[4000] = {0};
vector<string> LOVE[4000] = {0};
vector<string> LOWE[4000] = {0};
vector<string> LUCAS[4000] = {0};
vector<string> LUNA[4000] = {0};
vector<string> LYNCH[4000] = {0};
vector<string> LYONS[4000] = {0};
vector<string> MACK[4000] = {0};
vector<string> MALDONADO[4000] = {0};
vector<string> MALONE[4000] = {0};
vector<string> MANN[4000] = {0};
vector<string> MANNING[4000] = {0};
vector<string> MARQUEZ[4000] = {0};
vector<string> MARSHALL[4000] = {0};
vector<string> MARTIN[4000] = {0};
vector<string> MARTINEZ[4000] = {0};
vector<string> MASON[4000] = {0};
vector<string> MATTHEWS[4000] = {0};
vector<string> MAXWELL[4000] = {0};
vector<string> MAY[4000] = {0};
vector<string> MCCARTHY[4000] = {0};
vector<string> MCCOY[4000] = {0};
vector<string> MCDANIEL[4000] = {0};
vector<string> MCDONALD[4000] = {0};
vector<string> MCGEE[4000] = {0};
vector<string> MCKINNEY[4000] = {0};
vector<string> MCLAUGHLIN[4000] = {0};
vector<string> MEDINA[4000] = {0};
vector<string> MEJIA[4000] = {0};
vector<string> MENDEZ[4000] = {0};
vector<string> MENDOZA[4000] = {0};
vector<string> MEYER[4000] = {0};
vector<string> MILES[4000] = {0};
vector<string> MILLER[4000] = {0};
vector<string> MILLS[4000] = {0};
vector<string> MIRANDA[4000] = {0};
vector<string> MITCHELL[4000] = {0};
vector<string> MOLINA[4000] = {0};
vector<string> MONTGOMERY[4000] = {0};
vector<string> MONTOYA[4000] = {0};
vector<string> MOORE[4000] = {0};
vector<string> MORALES[4000] = {0};
vector<string> MORAN[4000] = {0};
vector<string> MORENO[4000] = {0};
vector<string> MORGAN[4000] = {0};
vector<string> MORRIS[4000] = {0};
vector<string> MORRISON[4000] = {0};
vector<string> MOSS[4000] = {0};
vector<string> MULLINS[4000] = {0};
vector<string> MUNOZ[4000] = {0};
vector<string> MURPHY[4000] = {0};
vector<string> MURRAY[4000] = {0};
vector<string> MYERS[4000] = {0};
vector<string> NAVARRO[4000] = {0};
vector<string> NEAL[4000] = {0};
vector<string> NELSON[4000] = {0};
vector<string> NEWMAN[4000] = {0};
vector<string> NEWTON[4000] = {0};
vector<string> NGUYEN[4000] = {0};
vector<string> NICHOLS[4000] = {0};
vector<string> NORMAN[4000] = {0};
vector<string> NORRIS[4000] = {0};
vector<string> NUNEZ[4000] = {0};
vector<string> OBRIEN[4000] = {0};
vector<string> OCHOA[4000] = {0};
vector<string> OCONNOR[4000] = {0};
vector<string> OLIVER[4000] = {0};
vector<string> OLSON[4000] = {0};
vector<string> ORTEGA[4000] = {0};
vector<string> ORTIZ[4000] = {0};
vector<string> OWENS[4000] = {0};
vector<string> PACHECO[4000] = {0};
vector<string> PADILLA[4000] = {0};
vector<string> PAGE[4000] = {0};
vector<string> PALMER[4000] = {0};
vector<string> PARK[4000] = {0};
vector<string> PARKER[4000] = {0};
vector<string> PARKS[4000] = {0};
vector<string> PARSONS[4000] = {0};
vector<string> PATEL[4000] = {0};
vector<string> PATTERSON[4000] = {0};
vector<string> PAUL[4000] = {0};
vector<string> PAYNE[4000] = {0};
vector<string> PEARSON[4000] = {0};
vector<string> PENA[4000] = {0};
vector<string> PEREZ[4000] = {0};
vector<string> PERKINS[4000] = {0};
vector<string> PERRY[4000] = {0};
vector<string> PERSON[4000] = {0};
vector<string> PETERS[4000] = {0};
vector<string> PETERSON[4000] = {0};
vector<string> PHAM[4000] = {0};
vector<string> PHILLIPS[4000] = {0};
vector<string> PIERCE[4000] = {0};
vector<string> PORTER[4000] = {0};
vector<string> POTTER[4000] = {0};
vector<string> POWELL[4000] = {0};
vector<string> POWERS[4000] = {0};
vector<string> PRICE[4000] = {0};
vector<string> QUINN[4000] = {0};
vector<string> RAMIREZ[4000] = {0};
vector<string> RAMOS[4000] = {0};
vector<string> RAMSEY[4000] = {0};
vector<string> RAY[4000] = {0};
vector<string> REED[4000] = {0};
vector<string> REESE[4000] = {0};
vector<string> REEVES[4000] = {0};
vector<string> REID[4000] = {0};
vector<string> REYES[4000] = {0};
vector<string> REYNOLDS[4000] = {0};
vector<string> RHODES[4000] = {0};
vector<string> RICE[4000] = {0};
vector<string> RICHARDS[4000] = {0};
vector<string> RICHARDSON[4000] = {0};
vector<string> RILEY[4000] = {0};
vector<string> RIOS[4000] = {0};
vector<string> RIVAS[4000] = {0};
vector<string> RIVERA[4000] = {0};
vector<string> ROBBINS[4000] = {0};
vector<string> ROBERTS[4000] = {0};
vector<string> ROBERTSON[4000] = {0};
vector<string> ROBINSON[4000] = {0};
vector<string> ROBLES[4000] = {0};
vector<string> RODGERS[4000] = {0};
vector<string> RODRIGUEZ[4000] = {0};
vector<string> ROGERS[4000] = {0};
vector<string> ROJAS[4000] = {0};
vector<string> ROMAN[4000] = {0};
vector<string> ROMERO[4000] = {0};
vector<string> ROSALES[4000] = {0};
vector<string> ROSE[4000] = {0};
vector<string> ROSS[4000] = {0};
vector<string> ROWE[4000] = {0};
vector<string> RUIZ[4000] = {0};
vector<string> RUSSELL[4000] = {0};
vector<string> RYAN[4000] = {0};
vector<string> SALAZAR[4000] = {0};
vector<string> SALINAS[4000] = {0};
vector<string> SANCHEZ[4000] = {0};
vector<string> SANDERS[4000] = {0};
vector<string> SANDOVAL[4000] = {0};
vector<string> SANTIAGO[4000] = {0};
vector<string> SANTOS[4000] = {0};
vector<string> SAUNDERS[4000] = {0};
vector<string> SCHMIDT[4000] = {0};
vector<string> SCHNEIDER[4000] = {0};
vector<string> SCHROEDER[4000] = {0};
vector<string> SCHULTZ[4000] = {0};
vector<string> SCHWARTZ[4000] = {0};
vector<string> SCOTT[4000] = {0};
vector<string> SERRANO[4000] = {0};
vector<string> SHARP[4000] = {0};
vector<string> SHAW[4000] = {0};
vector<string> SHELTON[4000] = {0};
vector<string> SHERMAN[4000] = {0};
vector<string> SILVA[4000] = {0};
vector<string> SIMMONS[4000] = {0};
vector<string> SIMON[4000] = {0};
vector<string> SIMPSON[4000] = {0};
vector<string> SIMS[4000] = {0};
vector<string> SINGH[4000] = {0};
vector<string> SMITH[4000] = {0};
vector<string> SNYDER[4000] = {0};
vector<string> SOLIS[4000] = {0};
vector<string> SOTO[4000] = {0};
vector<string> SPENCER[4000] = {0};
vector<string> STANLEY[4000] = {0};
vector<string> STEELE[4000] = {0};
vector<string> STEPHENS[4000] = {0};
vector<string> STEVENS[4000] = {0};
vector<string> STEVENSON[4000] = {0};
vector<string> STEWART[4000] = {0};
vector<string> STONE[4000] = {0};
vector<string> STRICKLAND[4000] = {0};
vector<string> SULLIVAN[4000] = {0};
vector<string> SUTTON[4000] = {0};
vector<string> SWANSON[4000] = {0};
vector<string> TATE[4000] = {0};
vector<string> TAYLOR[4000] = {0};
vector<string> TERRY[4000] = {0};
vector<string> THOMAS[4000] = {0};
vector<string> THOMPSON[4000] = {0};
vector<string> THORNTON[4000] = {0};
vector<string> TODD[4000] = {0};
vector<string> TORRES[4000] = {0};
vector<string> TOWNSEND[4000] = {0};
vector<string> TRAN[4000] = {0};
vector<string> TRUJILLO[4000] = {0};
vector<string> TUCKER[4000] = {0};
vector<string> TURNER[4000] = {0};
vector<string> VALDEZ[4000] = {0};
vector<string> VALENCIA[4000] = {0};
vector<string> VARGAS[4000] = {0};
vector<string> VASQUEZ[4000] = {0};
vector<string> VAUGHN[4000] = {0};
vector<string> VAZQUEZ[4000] = {0};
vector<string> VEGA[4000] = {0};
vector<string> VELASQUEZ[4000] = {0};
vector<string> WADE[4000] = {0};
vector<string> WAGNER[4000] = {0};
vector<string> WALKER[4000] = {0};
vector<string> WALLACE[4000] = {0};
vector<string> WALSH[4000] = {0};
vector<string> WALTERS[4000] = {0};
vector<string> WALTON[4000] = {0};
vector<string> WANG[4000] = {0};
vector<string> WARD[4000] = {0};
vector<string> WARNER[4000] = {0};
vector<string> WARREN[4000] = {0};
vector<string> WASHINGTON[4000] = {0};
vector<string> WATERS[4000] = {0};
vector<string> WATKINS[4000] = {0};
vector<string> WATSON[4000] = {0};
vector<string> WATTS[4000] = {0};
vector<string> WEAVER[4000] = {0};
vector<string> WEBB[4000] = {0};
vector<string> WEBER[4000] = {0};
vector<string> WEBSTER[4000] = {0};
vector<string> WELCH[4000] = {0};
vector<string> WELLS[4000] = {0};
vector<string> WEST[4000] = {0};
vector<string> WHEELER[4000] = {0};
vector<string> WHITE[4000] = {0};
vector<string> WILLIAMS[4000] = {0};
vector<string> WILLIAMSON[4000] = {0};
vector<string> WILLIS[4000] = {0};
vector<string> WILSON[4000] = {0};
vector<string> WISE[4000] = {0};
vector<string> WOLF[4000] = {0};
vector<string> WOLFE[4000] = {0};
vector<string> WONG[4000] = {0};
vector<string> WOOD[4000] = {0};
vector<string> WOODS[4000] = {0};
vector<string> WRIGHT[4000] = {0};
vector<string> WU[4000] = {0};
vector<string> YANG[4000] = {0};
vector<string> YOUNG[4000] = {0};
vector<string> ZHANG[4000] = {0};
vector<string> ZIMMERMAN[4000] = {0};

//List of Empty Array for First Names

//int sortnum;
//int counter1;
//int counter2;
//int p1ssn;
//int p2ssn;

void sortDataList(list<Data *> &l) {
  // Fill this in

	//Chose this size for comparison so if C++ compares int based on MSB or LSB it'd return asap 
	while
	//int p1ssn = stoi(p1->ssn.substr(0,2)) + stoi(p1->ssn.substr(4,5)) + stoi(p1->ssn.substr(7,9));
	//Create a quicksort
	//Create a bubble sort
	//
	
}


//idea
//use quicksort for last names
//insertion sort for first names
//insertion/radix for SSN
//
//idea 2
//create multiple bool lessThan for lessThan lastName, lessThan firstName, and lessThan ssn
//remove prototype function?
//
//idea 3 
//use bucket sort
//
//
//Insertion sort implementation
void insertionSort();
