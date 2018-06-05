/*
 * DbReader.h
 *
 *  Created on: 01.06.2018
 *      Author: Gangadhar Bobbili
 *       Email: Gangadhar.Bobbili@hotmail.com
 */

#ifndef LIBAFWDATABASE_SRC_DBREADER_H_
#define LIBAFWDATABASE_SRC_DBREADER_H_

#include <iostream>
using namespace std;

#include "DbBase.h"

class DbReader : public DbBase
{
public:
	string Read();
};

#endif /* LIBAFWDATABASE_SRC_DBREADER_H_ */
