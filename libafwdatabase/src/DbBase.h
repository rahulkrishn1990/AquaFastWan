/*
 * DbBase.h
 *
 *  Created on: 01.06.2018
 *      Author: Gangadhar Bobbili
 *       Email: Gangadhar.Bobbili@hotmail.com
 */

#ifndef LIBAFWDATABASE_SRC_DBBASE_H_
#define LIBAFWDATABASE_SRC_DBBASE_H_


#include <sqlite3.h>
#include <iostream>
using namespace std;

class DbBase
{
protected:
	void Init();
protected:
	sqlite3* _sqlite3;
};

#endif /* LIBAFWDATABASE_SRC_DBBASE_H_ */
