#--------------------------------------------------------------------------
# File and Version Information:
#  $Id$
#
# Description:
#  Module ExpNameDatabase...
#
#------------------------------------------------------------------------

"""Module for a class which provides mapping between experiment names and IDs.

@version $Id$

@author Andy Salnikov
"""


#------------------------------
#  Module's version from CVS --
#------------------------------
__version__ = "$Revision$"
# $Source$

#--------------------------------
#  Imports of standard modules --
#--------------------------------
import sys
import logging

#---------------------------------
#  Imports of base class module --
#---------------------------------

#-----------------------------
# Imports for other modules --
#-----------------------------
from AppUtils.AppDataPath import AppDataPath

#----------------------------------
# Local non-exported definitions --
#----------------------------------

def _tripleGen(fname):
    """generator for triples (expnum, instr, exper)"""
    for line in open(fname):
        num, instr, exper = line.split()
        num = int(num)
        yield num, instr, exper

#------------------------
# Exported definitions --
#------------------------

#---------------------
#  Class definition --
#---------------------
class ExpNameDatabase ( object ) :
    """Class which provides mapping between experiment names and IDs."""

    #----------------
    #  Constructor --
    #----------------
    def __init__ ( self, dbname = "ExpNameDb/experiment-db.dat" ) :
        """
        Constructor takes the name of the file containing the database
        File name is relative with respect to the $SIT_DATA (one of its components).
        If the file is not found an exception is generated.
        """

        # find experiment database file
        self.expdbpath = AppDataPath(dbname).path()
        if not self.expdbpath: raise ValueError("ExpNameDatabase: file name not found: " + dbname)

    #-------------------
    #  Public methods --
    #-------------------

    def getNames(self, id):
        """
        self.getNames(id: int) -> tuple of 2 strings
        
        Get instrument and experiment name given experiment ID. Takes experiment ID and 
        returns pair of strings, first string is instrument name, second is experiment name,
        both will be empty if ID is not known.
        """

        # scan database
        res = ("", "")
        for expnum, instr, exper in _tripleGen(self.expdbpath):
            if expnum == id:
                res = (instr, exper)
                break
        logging.debug("ExpNameDatabase.getNames(%d) -> %s", id, res)
        return res


    def getID(self, instrument, experiment):
        """
        self.getID(instrument: str, experiment: str) -> int
        
        Get experiment ID given instrument and experiment names. Instrument name may be empty 
        if experiment name is unambiguous. If instrument name is empty and experiment name is 
        ambiguous then first matching ID is returned. Returns experiment ID or 0 if 
        instrument/experiment is not known.
        """

        # scan database
        res = 0
        for expnum, instr, exper in _tripleGen(self.expdbpath):
            if exper == experiment and (not instrument or instr == instrument):
                res = expnum
                break
        logging.debug("ExpNameDatabase.getID('%s', '%s') -> %d", instrument, experiment, res)
        return res


    def getInstrumentAndID(self, experiment):
        """
        self.getInstrumentAndID(experiment: str) -> tuple of string and int
        
        Get instrument name and experiment ID for given experiment name. If experiment name is 
        ambiguous then first matching name and ID is returned. Takes experiment name and returns
        pair of instrument name and experiment ID, name will be empty if experiment is not known.
        """

        # scan database
        res = ("", 0)
        for expnum, instr, exper in _tripleGen(self.expdbpath):
            if exper == experiment:
                res = instr, expnum
        logging.debug("ExpNameDatabase.getID('%s') -> %d", experiment, res)
        return res


#
#  In case someone decides to run this module
#
if __name__ == "__main__" :

    # In principle we can try to run test suite for this module,
    # have to think about it later. Right now just abort.
    sys.exit ( "Module is not supposed to be run as main module" )
