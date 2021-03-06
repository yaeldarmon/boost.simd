//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing iround capabilities

    Computes the integer conversion of the round of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = iround(x);
    @endcode

    is similar to:

    @code
    as_integer_t<T> r = toints(round(x));
    @endcode

  **/
  const boost::dispatch::functor<tag::iround_> iround = {};
} }
#endif

#include <boost/simd/function/scalar/iround.hpp>
#include <boost/simd/function/simd/iround.hpp>

#endif
