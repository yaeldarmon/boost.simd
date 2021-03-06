//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-bitwise
    Function object implementing reversebits capabilities

    Returns the bits of the entry in reverse order.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = reversebits(x);
    @endcode

  **/
  const boost::dispatch::functor<tag::reversebits_> reversebits = {};
} }
#endif

#include <boost/simd/function/scalar/reversebits.hpp>
#include <boost/simd/function/simd/reversebits.hpp>

#endif
