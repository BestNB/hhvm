/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_TYPE_STRUCTURE_HELPERS_H_
#define incl_HPHP_TYPE_STRUCTURE_HELPERS_H_

#include <string>

#include "hphp/runtime/base/array-data.h"
#include "hphp/runtime/base/typed-value.h"

#include "hphp/runtime/vm/bytecode.h"


namespace HPHP {

/*
 * Checks whether the given cell is an instance of the class referred by
 * given named entity
 */
bool cellInstanceOf(const Cell* tv, const NamedEntity* ne);

/*
 * Resolves the given array as a type structure
 * Raises an error if the type structure contains a trait, typevar
 * or a function type
 * May throw if the type structure cannot be resolved
 */
Array resolveAndVerifyTypeStructure(const Array& ts);

/*
 * Checks whether the type of the given cell matches the type structure
 * Expects a resolved type structure
 */
bool checkTypeStructureMatchesCell(const Array& ts, Cell c1);

/*
 * In addition to regular checkTypeStructureMatchesCell, also populates the
 * error paths
 */
bool checkTypeStructureMatchesCell(
  const Array& ts,
  Cell c1,
  std::string& givenType,
  std::string& expectedType,
  std::string& errorKey
);

/*
 * Throws user catchable exception that tells the user what the given type is,
 * what the expected type is and which key it failed at, if applicable
 */
[[noreturn]] void throwTypeStructureDoesNotMatchCellException(
  std::string& givenType,
  std::string& expectedType,
  std::string& errorKey
);

}

#endif
