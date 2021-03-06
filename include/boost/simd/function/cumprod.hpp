//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMPROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing cumprod capabilities

    Computes the cumulated product of the vector elements

    Take care that overflow is very easy to get here especially for integral types.
    cimprod of char and unsigned char almost always overflow in SIMD !

    @par semantic:
    For any given vector @c x of type @c T:

    @code
    T r = cumprod(x);
    @endcode

    The function coincide with plus for floating point parameters.
    For integers is similar to:

    @code
    T r =x;
    for(int i=0;i < T::static_size; ++i)
      r[i]*= r[i-1];
    @endcode

  **/
  const boost::dispatch::functor<tag::cumprod_> cumprod = {};
} }
#endif

#include <boost/simd/function/scalar/cumprod.hpp>
#include <boost/simd/function/simd/cumprod.hpp>

#endif
