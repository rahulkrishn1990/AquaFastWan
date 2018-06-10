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

namespace aquafastwan {
namespace sqlite{

class DbBase
{
public:

    DbBase();

    ~DbBase();

protected:

    void Init();

    sqlite3 * _sqlite3;
};

} // sqlite
} // aquafastwan


#endif /* LIBAFWDATABASE_SRC_DBBASE_H_ */
