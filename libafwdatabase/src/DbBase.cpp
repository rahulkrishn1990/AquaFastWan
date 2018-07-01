/*
 * DbBase.cpp
 *
 *  Created on: 01.06.2018
 *      Author: Gangadhar Bobbili
 *       Email: Gangadhar.Bobbili@hotmail.com
 */

#include "DbBase.h"

namespace aquafastwan {
namespace sqlite{


DbBase::DbBase()
    : _sqlite3( 0 )
{

}

DbBase::~DbBase()
{
    if( _sqlite3 )
    {
        delete _sqlite3;
    }
}


void DbBase::Init()
{

}

} // sqlite
} // aquafastwan
