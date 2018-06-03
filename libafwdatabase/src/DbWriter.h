/*
 * DbWriter.h
 *
 *  Created on: 01.06.2018
 *      Author: Gangadhar Bobbili
 *       Email: Gangadhar.Bobbili@hotmail.com
 */

#ifndef LIBAFWDATABASE_SRC_DBWRITER_H_
#define LIBAFWDATABASE_SRC_DBWRITER_H_

#include <iostream>
using namespace std;

#include "DbBase.h"

class DbWriter : public DbBase
{
public:
	bool Write(string);
};

#endif /* LIBAFWDATABASE_SRC_DBWRITER_H_ */
