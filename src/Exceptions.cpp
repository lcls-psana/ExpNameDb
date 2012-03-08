//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class Exceptions...
//
// Author List:
//      Andy Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "ExpNameDb/Exceptions.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace ExpNameDb {

Exception::Exception(const ErrSvc::Context& ctx, const std::string& what)
  : ErrSvc::Issue(ctx, "ExpNameDb::Exception: " + what)
{
}

FileNotFoundError::FileNotFoundError(const ErrSvc::Context& ctx, const std::string& fname)
  : Exception(ctx, "file was not found: " + fname)
{
}

} // namespace ExpNameDb
