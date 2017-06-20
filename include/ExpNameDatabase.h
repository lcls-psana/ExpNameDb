#ifndef EXPNAMEDB_EXPNAMEDATABASE_H
#define EXPNAMEDB_EXPNAMEDATABASE_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class ExpNameDatabase.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------
#include <string>
#include <utility>
#include <sstream>

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "AppUtils/AppDataPath.h"

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
 *  @brief Class which provides mapping between experiment names and IDs.
 *
 *  This software was developed for the LCLS project.  If you use all or 
 *  part of it, please give an appropriate acknowledgment.
 *
 *  @version $Id$
 *
 *  @author Andy Salnikov
 */

class ExpNameDatabase  {
public:
  std::string theLocalData;
  bool localDat;

  /**
   *  @brief Constructor takes the name of the file containing the database
   *
   *  File name is relative with respect to the $SIT_DATA (one of its components).
   *  If the file is not found the exception is generated.
   *
   *  @param[in] fname  database file name, default is ExpNameDb/experiment-db.dat
   *
   *  @throw FileNotFoundError if file does not exist
   */
  explicit ExpNameDatabase (const std::string fname = "ExpNameDb/experiment-db.dat");

  /**
   *  @brief Get instrument and experiment name given experiment ID.
   *
   *  @param[in] id    Experiment ID.
   *  @return Pair of strings, first string is instrument name, second is experiment name,
   *         both will be empty if ID is not known.
   *
   */
  std::pair<std::string, std::string> getNames(unsigned id) const;

  /**
   *  @brief Get experiment ID given instrument and experiment names.
   *
   *  Instrument name may be empty if experiment name is unambiguous. If instrument name
   *  is empty and experiment name is ambiguous then first matching ID is returned.
   *
   *  @param[in] instrument   Instrument name.
   *  @param[in] experiment   Experiment name.
   *  @return Experiment ID or 0 if instrument/experiment is not known.
   *
   */
  unsigned getID(const std::string& instrument, const std::string& experiment) const;

  /**
   *  @brief Get instrument name and experiment ID for given experiment name.
   *
   *  If experiment name is ambiguous then first matching name and ID is returned.
   *
   *  @param[in] experiment   Experiment name.
   *  @return Pair of instrument name and experiment ID, name will be empty if experiment is not known.
   *
   */
  std::pair<std::string, unsigned> getInstrumentAndID(const std::string& experiment) const;

protected:

private:

  AppUtils::AppDataPath m_path;
};

} // namespace ExpNameDb

#endif // EXPNAMEDB_EXPNAMEDATABASE_H
