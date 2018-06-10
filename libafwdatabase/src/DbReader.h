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
#include "DbBase.h"

namespace aquafastwan {
namespace sqlite{


class DbReader : public DbBase
{
public:
    std::string Read();
};

} // sqlite
} // aquafastwan


#endif /* LIBAFWDATABASE_SRC_DBREADER_H_ */
