#include <iostream>
using namespace std;

#include <QDebug>
#include <QString>

#include "AtPhClient.h"

int main(int argc, char* argv[])
{
	AtPhClient atPhClient;
	atPhClient.PhReader();
	return 0;
}
