//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQR_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQR_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing sqr_abs capabilities

    Computes the square of the absolute value of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqr_abs(x);
    @endcode

    is equivalent to:

    @code
    T r = sqr(abs(x));
    @endcode

    @par Alias

    @c sqr_modulus

  **/
  const boost::dispatch::functor<tag::sqr_abs_> sqr_abs = {};
} }
#endif

#include <boost/simd/function/scalar/sqr_abs.hpp>
#include <boost/simd/function/simd/sqr_abs.hpp>

#endif
