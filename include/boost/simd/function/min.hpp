//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing min capabilities

    Computes the smallest of its parameter.

    @par semantic:
    For any given value @c x and @c y of type @c T:

    @code
    T r = min(x, y);
    @endcode

    is similar to:

    @code
    T r = (x < y) ? x : y;
    @endcode

    @see minnum, minnummag, minmag

  **/
  const boost::dispatch::functor<tag::min_> min = {};
} }
#endif

#include <boost/simd/function/scalar/min.hpp>
#include <boost/simd/function/simd/min.hpp>

#endif
