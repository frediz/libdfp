/* Returns true if x and y have the same exponent

   Copyright (C) 2006 IBM Corporation.
   Copyright (C) 2007, 2009 Free Software Foundation, Inc.

   This file is part of the Decimal Floating Point C Library.

   Author(s): Joseph Kerian <jkerian@us.ibm.com>

   The Decimal Floating Point C Library is free software; you can
   redistribute it and/or modify it under the terms of the GNU Lesser
   General Public License version 2.1.

   The Decimal Floating Point C Library is distributed in the hope that
   it will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU Lesser General Public License version 2.1 for more details.

   You should have received a copy of the GNU Lesser General Public
   License version 2.1 along with the Decimal Floating Point C Library;
   if not, write to the Free Software Foundation, Inc., 59 Temple Place,
   Suite 330, Boston, MA 02111-1307 USA.

   Please see libdfp/COPYING.txt for more information.  */

#ifndef _DECIMAL_SIZE
#  include <decimal32.h>
#  define _DECIMAL_SIZE 32
#endif

#include <decContext.h>
#include <decNumber.h>
#include <math.h>

#define FUNCTION_NAME samequantum

#include <dfpmacro.h>

_Bool
INTERNAL_FUNCTION_NAME (DEC_TYPE x, DEC_TYPE y)
{
  decNumber dn_x;
  decNumber dn_y;

  FUNC_CONVERT_TO_DN(&x, &dn_x);
  FUNC_CONVERT_TO_DN(&y, &dn_y);

  if(___decNumberIsNaN(&dn_x) && ___decNumberIsNaN(&dn_y))
    return true;
  if(___decNumberIsNaN(&dn_x) || ___decNumberIsNaN(&dn_y))
    return false;
  if(___decNumberIsInfinite(&dn_x) && ___decNumberIsInfinite(&dn_y))
    return true;
  if(___decNumberIsInfinite(&dn_x) || ___decNumberIsInfinite(&dn_y))
    return false;

  return (dn_x.exponent + dn_x.digits == dn_y.exponent + dn_y.digits);
}

weak_alias (INTERNAL_FUNCTION_NAME, EXTERNAL_FUNCTION_NAME)
