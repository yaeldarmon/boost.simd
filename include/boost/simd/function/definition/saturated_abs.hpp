//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 NumScale J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_SATURATED_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_SATURATED_ABS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/definition/abss.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
  @ingroup group-arithmetic

    Computes the saturated absolute value of its parameter.

    This is an alias of function @c abss

    @see abss
  **/
  template<typename T> auto saturated_abs(T const& x);
#endif
  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::abss_,saturated_abs);

} }

#endif
