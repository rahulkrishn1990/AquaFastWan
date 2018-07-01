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
#include "DbBase.h"

namespace aquafastwan {
namespace sqlite{

class DbWriter : public DbBase
{
public:
    bool Write(const std::string & str);
};

} // sqlite
} // aquafastwan


#endif /* LIBAFWDATABASE_SRC_DBWRITER_H_ */
