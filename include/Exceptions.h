#ifndef EXPNAMEDB_EXCEPTIONS_H
#define EXPNAMEDB_EXCEPTIONS_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class Exceptions.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------
#include "ErrSvc/Issue.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace ExpNameDb {

/// @addtogroup ExpNameDb

/**
 *  @ingroup ExpNameDb
 *
 *  @brief Base class for all exception classes for ExpNameDb package.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov
 */

class Exception : public ErrSvc::Issue {
public:

  /// Constructor takes the reason for an exception
  Exception(const ErrSvc::Context& ctx, const std::string& what);

};

/// Exception thrown for unknown EPICS PV name
class FileNotFoundError : public Exception {
public:

  FileNotFoundError(const ErrSvc::Context& ctx, const std::string& fname);

};

} // namespace ExpNameDb

#endif // EXPNAMEDB_EXCEPTIONS_H
